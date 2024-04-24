#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

/*
0番目から7番目のbitを取得。

*/

int main()
{
    char a;
    char b;
    int i;

    a = 'a';
    b = 0;
    i = 0;
    while (i < 8)
    {
        if (a & (1<<i))
            b |= (1<<i);
        i++;
    }
    printf("%c\n", b);
    return 0;
}

// int main(void)
// {
//     unsigned int sec = 3;
//     sigset_t set;

//     // シグナル集合を空にし、SIGINT 追加
//     sigemptyset(&set);
//     sigaddset(&set, SIGINT);

//     // SIGINT をブロック (保留) する 
//     sigprocmask(SIG_BLOCK, &set, NULL);
//     printf("Block the SIGINT for %d sec\n", sec);

//     sleep(sec);

//     // SIGINT のブロックを解除する
//     printf("\nPassed %d sec, unblock the SIGINT\n", sec);
//     sigprocmask(SIG_UNBLOCK, &set, NULL);
//     sleep(2);
//     printf("Done !\n");

//     return 0;
// }
