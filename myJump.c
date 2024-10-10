#include <stdio.h>

int main(){
int x=5;
int y=33;
int test = x<=y;
int result;
if (test==1) goto Else;
result=x-y;
goto Done;
Else:
result=y-x;
Done:
printf("result:%d\n",result);
}

