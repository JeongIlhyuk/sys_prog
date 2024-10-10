#include <stdio.h>

int main(){
	printf("L0");
	fork();
	printf("L1");
	fork();
	printf("Bye");
	
	return 0;
}
