#include "../includes/pipex.h"

/*
コマンドライン引数で受けた取ったものをexecve関数に渡します。

子プロセスは親プロセスのデータ、ヒープ、スタックかの各空間を複製し、
取得するが子プロセスで変数を変更しても親プロセスの変数の値に影響はない。
if ((pid== fork) < 0)~elseif (pid == 0)
子プロセスは必ず０が帰るのでif文で0が帰った時に子プロセスのコードを書く、
その後子プロセスのIDが帰ってくる親プロセスはelse文で指定して記述する。

https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901

*/
void    pipex(int f1, int f2, char *cmd1, char *cmd2)
{
    int   end[2];
    int   status;
    pid_t child1;
    pid_t child2;
    pipe(end);
    child1 = fork();
    if (child1 < 0)
         return (perror("Fork: "));
    if (child1 == 0)
        child_one(f1, cmd1);
    child2 = fork();
    if (child2 < 0)
         return (perror("Fork: "));
    // if (child2 == 0)
    //     child_two(f2, cmd2);
    close(end[0]);         // this is the parent
    close(end[1]);         // doing nothing
    waitpid(child1, &status, 0);  // supervising the children
    waitpid(child2, &status, 0);  // while they finish their tasks
}
int main(int ac, char **av, char **envp)
{
    int	i;
	int	input_file;
	int	output_file;

    if (ac < 5)
        return 0;
    i = 2;
    input_file = open(av[1], O_RDONLY, 0664);
    output_file = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    while (i < ac - 1)
    {
        printf("%s\n", av[i]);
        i++;
    }
    return 0;
}