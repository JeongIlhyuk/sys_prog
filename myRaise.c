#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum) {
    printf("Received signal %d\n", signum);
}

int main() {
    signal(SIGUSR1, signal_handler);
    printf("Sending SIGUSR1 to self...\n");
    raise(SIGUSR1);
    sleep(1);  // 시그널 처리를 위한 대기
    return 0;
}
