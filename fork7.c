#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t pid;
	pid=fork();
	
	if(pid==0){
		printf("Child %d terminated\n",getpid());
		exit(0);
	}else{
		printf("Parent %d in loop\n",getpid());
		//while(1);
	}
}
