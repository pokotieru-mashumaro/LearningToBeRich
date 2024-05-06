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


client -> server
SIGUSR1 = bit ==0 のときのフラグ
SIGUSR2 = bit ==1 のときのフラグ

server -> client
SIGUSR1
SIGUSR2

https://web-ext.u-aizu.ac.jp/course/osrtk/exercise/ex/ex03/ex03.html
https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361#0-%E3%83%93%E3%83%83%E3%83%88%E3%81%A8%E3%81%AF

*/

static void get_char_from_client(int sig, siginfo_t *info, void *context)
{
  static int client_pid;
  static char c;
  static int i;
  int kill_flag;

  (void) context;
  if (!client_pid)
    client_pid = info->si_pid;
  if (sig == SIGUSR2)
    c |= (1 << i);
  i++;
  if (i == 8)
  {
    i = 0;
    if (c == '\0')
    {
      if (sig == SIGUSR1)
        kill_flag = kill(client_pid, SIGUSR1);
      else
        kill_flag = kill(client_pid, SIGUSR2);
      client_pid = 0;
      write(1, "\n", 1);
      return ;
    }
    write(1, &c, 1);
    c = 0;
  }
  return;
}

int main(void)
{
  struct sigaction sa;

  printf("pid: %d\n", getpid());

  sigemptyset(&sa.sa_mask); // シグナルマスクをクリアにする
  sa.sa_sigaction = get_char_from_client;
  sa.sa_flags = SA_SIGINFO; // 送信元を知ることができる
  sigaction(SIGUSR1, &sa, NULL);
  sigaction(SIGUSR2, &sa, NULL);
  while (1)
    pause();
  return 0;
}
