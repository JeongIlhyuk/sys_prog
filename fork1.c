#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
	pid_t pid;
	pid = fork();
	int x=1;
	if(pid == 0){
		printf("Child getpid:%d getppid:%d x == %d\n",getpid(),getppid(),++x);
	}else{
		printf("Parent getpid:%d getppid:%d x == %d\n",getpid(),getppid(),--x);
	}
	printf("Bye from pid %d with x == %d\n",getpid(),x);

	return 0;
}
