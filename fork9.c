#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	pid_t pid=fork();
	int child_status;

	if(pid==0){
		printf("HC %d\n",getpid());	
	}else{
		printf("HP %d\n",getpid());
		wait(&child_status);
		printf("CT\n");
	}
	printf("bye %d\n",getpid());
}
