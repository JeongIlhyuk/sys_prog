#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t pid;
	int x=1;
	pid=fork();
	if(pid==0){
		printf("Child has %d\n",++x);
	}else{
		printf("Parent has %d\n",--x);
	}
	printf("Bye from %d with %d\n",getpid(),x);
}
