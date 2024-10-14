#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void int_handler(int sig){
	printf("Process %d received signal %d\n",getpid(),sig);
	//exit(0);
	return;
}
int main(){
	pid_t pid[5],wpid;
	int i,child_status;
	
	signal(SIGINT, int_handler);
	for (i = 0; i < N; i++)
		if ((pid[i] = fork()) == 0)
		while(1); /* Child infinite loop */
		/* Parent terminates the child processes */
	for (i = 0; i < N; i++) {
		printf("Killing process %d\n", pid[i]);
		kill(pid[i], SIGINT);
	}
	/* Parent reaps terminated children */
	for (i = 0; i < N; i++) {
		pid_t wpid = wait(&child_status);
		if (WIFEXITED(child_status))
			printf("Child %d terminated with exit status %d\n",wpid, WEXITSTATUS(child_status));
		else
			printf("Child %d terminated abnormally\n", wpid);
	}		
}
