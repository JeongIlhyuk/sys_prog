#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	int childStatus;
	if(fork()==0)
		execl("/bin/cp","cp","execlEx.c","eE.c",NULL);
	wait(&childStatus);
	printf("copy success\n");
}
