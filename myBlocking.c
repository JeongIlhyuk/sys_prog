#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	pid_t wpid,pid=fork();
	int status;
	if(pid>0){
		printf("Parent waiting for %d\n",pid);
	//	sleep(3);
		waitpid(pid,&status,WNOHANG);
		printf("Parent finished\n");
		return 0;
	}
	else if(pid==0){
		printf("This is child\n");
		while(1);
	}
}
