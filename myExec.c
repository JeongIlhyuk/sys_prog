#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	putenv("MY_V=-l");
	char* option = getenv("MY_V");
	execlp("ls","fuckthat",option,NULL);
	return 1;
}
