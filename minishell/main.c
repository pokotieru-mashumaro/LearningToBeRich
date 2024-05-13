#include "minishell.h"

#define STDERR 2
#define MINISHELL "\x1b[33mMINISHELL$\x1b[m "

void minishell(char **envp);
void sig_int_input();
void sig_quit_input();

int main(int ac, char **av, char **ep)
{
    if (ac == 1)
        minishell(ep);
}

void minishell(char **ep)
{
    char *line;
    int ret;

    ret = 0;
    while (1)
    {
        char *line;

        ft_putstr_fd(MINISHELL, STDERR);
        if (signal(SIGINT, sig_int_input) == SIG_ERR)
        {
            ft_putstr_fd(strerror(errno), STDERR);
            exit(1);
        }
        if (signal(SIGQUIT, sig_quit_input) == SIG_ERR)
        {
            ft_putstr_fd(strerror(errno), STDERR);
            exit(1);
        }
        line = get_next_line(0);
        if (ft_strlen(line) == 0)
        {
            ft_putstr_fd("exit\n", STDERR);
            exit(ret);
        }

        //ここに実行部が来ます！！！
        ft_putstr_fd(line, STDERR);
        free(line);
    }
}

void sig_int_input()
{
    ft_putstr_fd("\b\b  \b\n", STDERR);
    ft_putstr_fd(MINISHELL, STDERR);
}

void sig_quit_input()
{
    ft_putstr_fd("\b\b  \b\b", STDERR);
}