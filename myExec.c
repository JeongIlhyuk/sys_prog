#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	if(fork()==0)
		execl("/bin/cp","cp","foo","bar",NULL);
	wait(NULL);
	printf("copy completed\n");
}
