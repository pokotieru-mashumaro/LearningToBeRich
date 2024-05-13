#include "minishell.h"

# define STDERR 2
# define MINISHELL "MINISHELL$ "

void minishell(char **envp);
void sig_int_input();
void sig_quit_input();

// envpは環境変数
int main(int argc, char **argv, char **envp)
{
   if (argc == 1)
       minishell(envp);
}

void minishell(char **envp)
{
  char *line;
  int  ret;
  
  ret = 0;
  while(1)
  {
      char *line;
      
      ft_putstr_fd(MINISHELL, STDERR);
	   // ctrl+C, ctrl+\ の指示
	   if (signal(SIGINT, sig_int_input) == SIG_ERR)
	   {
	       ft_putstr_fd(strerror(errno), STDERR);
		   exit (1);
	   }
	   if (signal(SIGQUIT, sig_quit_input) == SIG_ERR)
	   {
	       ft_putstr_fd(strerror(errno), STDERR);
		   exit (1);
  	   }
      // 文字を受け取る
      line = get_next_line(0);
      if (ft_strlen(line) == 0)
		{
	        ft_putstr_fd("exit\n", STDERR);
			exit (ret);
		}
      ft_putstr_fd(line, STDERR);
      ft_putstr_fd("\n", STDERR);
      free(line);
  }
}

void	sig_int_input()
{
	ft_putstr_fd("\b\b  \b\n", STDERR);
	ft_putstr_fd(MINISHELL, STDERR);
}

void	sig_quit_input()
{
	ft_putstr_fd("\b\b  \b\b", STDERR);
}