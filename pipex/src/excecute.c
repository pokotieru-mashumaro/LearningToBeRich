#include "../includes/pipex.h"
#include <stdio.h>
#include <unistd.h>

// void execute(char *s, char **envp)
// {
// 	char **cmd;

// 	cmd = ft_split(s, ' ');

// }

int main(int argc, char **argv, char **envp)
{
  char    command[] = "/bin/cat";
  char    *exargv[] = {"cat", "-n", NULL};
  char    *exenvp[] = {NULL};
  int     return_code = 0;

  if (argc == 2) {
    /* 実行時引数（パス名）をexecveの引数にする */
    exargv[2] = argv[1];
    if (execve(command, exargv, exenvp) == -1) {
      printf("%sコマンドが実行できませんでした\n", command);
      perror("  ");
      return_code = 1;
    }
  }
  else {
    printf("実行時引数の数が不当です\n");
    return_code = 2;
  }

  return return_code;
}
