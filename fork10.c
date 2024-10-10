#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	pid_t pid[N];
	int child_status;
	for(int i=0;i<N;i++){
		if((pid[i] = fork())==0)
			exit(100+i);
	}
	for(int i=0;i<N;i++){
		pid_t wpid = waitpid(pid[i],&child_status,0);
		if(WIFEXITED(child_status))
			printf("child exit pid:%d status:%d\n",wpid,WEXITSTATUS(child_status));
	}
}
