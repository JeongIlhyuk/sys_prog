#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(){
	pid_t pid;
	pid = fork();
	int child_status;
	if(pid == 0){
		printf("from child pid:%d\n",getpid());
	}else{
		printf("from parent pid:%d\n",getpid());
		wait(&child_status);
		printf("child's terminated\n");
	}
	
	printf("Bye pid:%d\n",getpid());
	exit(0);
}
