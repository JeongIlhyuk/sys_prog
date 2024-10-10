#include <stdio.h>

int main(){
	long result =0;
	long x = 199;//11000111
loop:
	result += x & 0x1;
	x>>=1;
	if(x>0)goto loop;
	printf("result:%ld\n",result);
}
