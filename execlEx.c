#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t pid = fork();
	if(pid == 0){
		execl("/bin/ps","ps",NULL);
		printf("This shouldn't be implemented\n");
	}else{
		printf("Parent\n");
	}
	return 0;
}
