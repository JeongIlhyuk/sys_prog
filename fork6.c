#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void print(){
	printf("atexit\n");
}
int main(){
	atexit(print);
	exit(0);
}
