#include <stdio.h>

int main(){
	int x=15;
	int result=0;
	Loop:
	result += x & 0x1;
	x>>=1;
	if(x!=0)goto Loop;
	printf("result:%d\n",result);

	return 0;
}
