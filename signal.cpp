#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int block_sigcld(){
	struct sigaction sig;
	memset(&sig,0,sizeof(sig));
	sig.sa_handler=SIG_IGN;
	sig.sa_flags|=SA_NOCLDWAIT;
	sigemptyset(&sig.sa_mask);
	if(sigaction(SIGCLD,&sig,NULL)<0)
		return -errno;
	return 0;
}

int main(){
	if(block_sigcld()<0){
		printf("block sigcld error");
		exit(EXIT_FAILURE);
	}
	pid_t pid=0;
	pid=fork();
	if(pid<0)
		exit(EXIT_FAILURE);
	if(pid==0){
		exit(EXIT_SUCCESS);
	}
	sleep(5);
	exit(EXIT_SUCCESS);
}

