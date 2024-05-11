#include "../includes/pipex.h"

/*
コマンドライン引数で受けた取ったものをexecve関数に渡します。

子プロセスは親プロセスのデータ、ヒープ、スタックかの各空間を複製し、
取得するが子プロセスで変数を変更しても親プロセスの変数の値に影響はない。
if ((pid== fork) < 0)~elseif (pid == 0)
子プロセスは必ず０が帰るのでif文で0が帰った時に子プロセスのコードを書く、
その後子プロセスのIDが帰ってくる親プロセスはelse文で指定して記述する。

https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901
https://rakiyama0229.hatenablog.jp/entry/2021/07/29/135959
https://www.ne.jp/asahi/hishidama/home/tech/c/pipe.html
https://hayataka2049.hatenablog.jp/entry/2018/11/08/185349
*/
void    child(char *s, char **envp)
{
    pid_t	pid;
	int		end[2];

	if (pipe(end) == -1)
		return;
	pid = fork();
    if (pid < 0)
        return;
    else if (pid == 0)
    {
        //child
        close(end[0]);
        dup2(end[1], STDOUT_FILENO);
    }
    else if (pid > 0)
    {
        //parent
        close(end[1]);
        dup2(end[0], STDIN_FILENO);
        waitpid(pid, NULL, 0);
    }
}

int main(int ac, char **av, char **envp)
{
    int	i;
	int	input_file;
	int	output_file;

    if (ac < 5)
        return 0;
    i = 2;
    input_file = open(av[1], O_RDONLY);
    output_file = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    while (i < ac - 1)
    {
        i++;
    }
    return 0;
}
