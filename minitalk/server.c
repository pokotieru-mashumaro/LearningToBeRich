#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

/*
やること：

1：サーバー起動
起動後PIDを表示
文字列受信でサーバーはそれを表示（高速）
サーバーは再起動することなく、複数のクライアントから連続で文字列を受信できなくてはいけない
UNIXシグナルを使用可能（SIGUSR1、SIGUSR2）

2：クライアントのパラメータ
サーバーのPID、送る文字列
パラメータとして渡された文字列をサーバーに送信
*/

/*
bonus:
- サーバーは、受信したすべてのメッセージに対して、シグナルをクライアントに送り返すことで確認します。
- ユニコード文字対応！
*/

/*
大まかな流れ：
サーバー起動
pid出力

クライアント起動
PIDを元に文字列を送信




*/

static int g_sig;
static siginfo_t g_siginfo;

static void f(siginfo_t info)
{

}

//グローバル変数ok
int main(int ac, char **av)
{
    struct sigaction sa;

    printf ("pid: %d\n", getpid());

    sigemptyset(&sa.sa_mask); //シグナルマスクをクリアにする
    sa.sa_handler = f;
    sa.sa_flags = SA_SIGINFO; //送信元を知ることができる
    sigaction(SIGINT, &sa, NULL);

    while (1)
		pause();
    return 0;
}
