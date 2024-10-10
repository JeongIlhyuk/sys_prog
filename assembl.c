#include <stdio.h>
#define NUM 5

long plus(long x, long y){
	return x+y;
}

void sumstore5x(long x, long y, long*dest){
	long t=NUM*plus(x,y);
	*dest = t;
}

int main(){
	return 0;
}
