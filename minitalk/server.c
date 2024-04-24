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

サーバーが受信


https://web-ext.u-aizu.ac.jp/course/osrtk/exercise/ex/ex03/ex03.html
https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361#0-%E3%83%93%E3%83%83%E3%83%88%E3%81%A8%E3%81%AF

*/

static int g_sig;
static siginfo_t g_siginfo;

static void f(siginfo_t info)
{
}

void get_char_from_client(int sig)
{
  static char c;
  static int i;

  if (sig == SIGUSR2)
    c |= (1 << i);

  i++;
  if (i == 8)
    i = 0;
}

int main(int ac, char **av)
{
  struct sigaction sa;

  printf("pid: %d\n", getpid());

  sigemptyset(&sa.sa_mask); // シグナルマスクをクリアにする
  sa.sa_handler = f;
  sa.sa_flags = SA_SIGINFO; // 送信元を知ることができる
  sigaction(SIGINT, &sa, NULL);

  while (1)
    pause();
  return 0;
}
