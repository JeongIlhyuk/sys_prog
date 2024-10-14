#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	if (argc != 2) {
        	fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        	exit(EXIT_FAILURE);
      	 }

	int pipefd[2];
	char buf;

	if(pipe(pipefd)==-1){
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	
	pid_t pid;
	pid = fork();
	
	if(pid==0){
		close(pipefd[1]);
		while(read(pipefd[0],&buf,1)>0){
			write(STDOUT_FILENO,&buf,1);
		}
		write(STDOUT_FILENO,"\n",1);
		close(pipefd[0]);
		_exit(EXIT_SUCCESS);
	}else{
		close(pipefd[0]);
		write(pipefd[1],argv[1],strlen(argv[1]));
		close(pipefd[1]);
		wait(NULL);
		exit(EXIT_SUCCESS);
	}

}
