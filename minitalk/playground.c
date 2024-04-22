#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

int main(void)
{
    unsigned int sec = 3;
    sigset_t set;

    // シグナル集合を空にし、SIGINT 追加
    sigemptyset(&set);
    sigaddset(&set, SIGINT);

    // SIGINT をブロック (保留) する 
    sigprocmask(SIG_BLOCK, &set, NULL);
    printf("Block the SIGINT for %d sec\n", sec);

    sleep(sec);

    // SIGINT のブロックを解除する
    printf("\nPassed %d sec, unblock the SIGINT\n", sec);
    sigprocmask(SIG_UNBLOCK, &set, NULL);
    sleep(2);
    printf("Done !\n");

    return 0;
}
