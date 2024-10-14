#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
int main(){
alarm(5);
while(1);
return 0;
}
