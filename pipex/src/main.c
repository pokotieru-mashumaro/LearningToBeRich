#include "../includes/pipex.h"

void cmd(char *cmd_origin, char **envp)
{
	char **cmd;

	cmd = ft_split(cmd_origin, ' ');

}

//再帰関数
void    hakanaiyume(char **av, char **envp, int firing_order, int output_file)
{
    pid_t	pid;
	int		end[2];

	if (firing_order > 2)
		hakanaiyume(av, envp, firing_order - 1, -42);
	if (pipe(end) == -1)
		return;
	if (output_file != -42)
	{
		printf("%d 最後のコマンド\n", firing_order);
		dup2(output_file, STDOUT_FILENO);
		printf("output に記載される!!\n");
	}
	pid = fork();
    if (pid < 0)
        return;
    else if (pid == 0)
    {
		printf("%d child\n", firing_order);
        //child
        close(end[0]);
        dup2(end[1], STDOUT_FILENO);
    }
    else if (pid > 0)
    {
		printf("%d parent\n", firing_order);
        //parent
        close(end[1]);
        dup2(end[0], STDIN_FILENO);
        waitpid(pid, NULL, 0);
    }
}

void try(int i)
{
	if (i > 2)
		try(i - 1);
	printf("%d\n", i);
}

int main(int ac, char **av, char **envp)
{
	int	input_file;
	int	output_file;

	// try(5);
    if (ac < 5)
        return 0;
    input_file = open(av[1], O_RDONLY);
    output_file = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(input_file, STDIN_FILENO);

	//発火!!!!
	hakanaiyume(av, envp, ac - 2, output_file);
    return 0;
}
