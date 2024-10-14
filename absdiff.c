#include <stdio.h>

long absdiff(long x, long y){
	long result;
	int ntest = x-y;
	if(ntest > 0) goto Else;
	result = y-x;
	goto Done;
	Else:
	result = x-y;
	Done:
	return result;
}

int main(){
	int r= absdiff(5,8);
	printf("%d\n",r);
	return 0;
}
