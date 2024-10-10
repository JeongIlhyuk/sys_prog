#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	printf("L0\n");
	if(fork()!=0){
		printf("L1\n");
		if(fork()!=0){
			printf("L2\n");
			if(fork()!=0){
			printf("L3\n");
			}
		}
	}
	printf("Bye from pid %d\n",getpid());
}
