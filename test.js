function ShowUnit(id0,id1,id2){
	this.id=id0;
	this.show_id=id1;
	this.hide_id=id2;
	this.show=function() {
		if(document.getElementById(this.id).checked){
			document.getElementById(this.show_id).stype.display="";
			document.getElementById(this.hide_id).stype.display="none";
		}else{
			document.getElementById(this.show_id).stype.display="none";
			document.getElementById(this.hide_id).stype.display="false";
		}
	};
	this.set_id_checked=function(is_check){
		if(is_check)
			document.getElementById(this.id).checked="checked";
		else
			document.getElementById(this.id).checked="";
	}
}
