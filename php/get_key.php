<?php
error_reporting(E_ALL);
function gen_key_file($keyname){
	$cmd="/usr/local/sbin/dnssec-keygen -a hmac-md5 -b 128 -n HOST -r /dev/urandom ".$keyname;
	$handle=popen($cmd." 2>&1 ","r");
	var_dump($handle);
	while(($line=fgets($handle))){
		var_dump($line);
		$line=trim($line);
		if(false!==strpos($line,$keyname))
			break;
	}
	pclose($handle);
	var_dump($line);
	return $line;
}

function gen_share_key($keyname){
	$file=gen_key_file($keyname);
	if(!$file){
		return false;
	}
	$handle=fopen($file.".key","r");
	$line=fgets($handle);
	$line=trim($line);
	$arry=explode(" ",$line);
	fclose($handle);
	unlink($file.".key");
	unlink($file.".private");
	if(count($arry)<7)
		return false;
	return $arry[6];
}

function display_key(){
	$key=gen_share_key("key");
	if(!$key)
		$key="faile";
	echo $key;
}
?>

<html>
<b>key:</b> <?php display_key();?>
<p>
<b>path:</b> <?php echo getcwd();?>
</p>
</html>
