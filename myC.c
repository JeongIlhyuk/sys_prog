#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigtstp_handler(int signum) {
    printf("Received SIGTSTP. Suspending...\n");
}

void sigcont_handler(int signum) {
    printf("Received SIGCONT. Continuing...\n");
}

int main() {
    //signal(SIGTSTP, sigtstp_handler);
    //signal(SIGCONT, sigcont_handler);

    int count = 0;
    while(1) {
        printf("Count: %d\n", count++);
        sleep(1);
    }

    return 0;
}
