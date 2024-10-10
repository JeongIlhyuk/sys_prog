#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    
    pid = fork();
    
    if (pid == 0) {
        printf("Running child %d\n", getpid());
        while(1);
    } else {
        printf("Terminating parent %d\n", getpid());
        exit(0);
    }
}
