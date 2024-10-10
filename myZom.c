#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
	if(fork()==0){
		printf("Child in infinite loop pid:%d\n",getpid());
		while(1){
		}
	}else{
		printf("Parent is terminated");
		exit(0);
	}
}
