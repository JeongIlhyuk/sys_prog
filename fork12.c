#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

//#define N 5

int main(){
	pid_t pid[N];
	int child_status;
	for(int i=0; i<N;i++)
		if((pid[i]=fork())==0)
			exit(100+i);
			//while(1);
//	for(int i=0;i<N;i++){
//		printf("Killing process pid %d\n",pid[i]);
//		kill(pid[i],SIGINT);
//	}
	pid_t wpid;
	for(int i=0;i<N;i++){
		wpid = waitpid(-1,&child_status,WNOHANG);
		if(WIFEXITED(child_status)){
			printf("Child terminated pid:%d status:%d\n",wpid,WEXITSTATUS(child_status));
		}else{
			printf("Child terminated abnormally pid:%d\n",wpid);
		}

	}
}
