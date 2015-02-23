#include "create_proc.h"
#include <sys/types.h>
#include <string.h>
#include <error.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_PATH 1024

static off_t offset=0;

int main(int argc,char **argv){
	char path[MAX_PATH];
	if(snprintf(path,MAX_PATH,"%s%s","/proc/",PROC_NAME)>=MAX_PATH){
		error(EXIT_FAILURE,EFAULT,"man: construct filename error");
	}
	/// 计算参数
	long off=0;
	if(argc>=2)
		off=atol(argv[1]);
	if(off>=0)
		offset=off;
	/// 输出文件
	int fd=open(path,O_RDONLY);
	if(fd<0)
		error(EXIT_FAILURE,errno,"main: open file %s error",path);
	lseek(fd,offset,SEEK_SET);
	char ch;
	while(read(fd,&ch,sizeof(ch)>0)){
		printf("%c",ch);
	}
	close(fd);
}

