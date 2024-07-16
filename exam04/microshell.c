/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:02:13 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/07/14 23:41:07 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void	ft_putstr_fd(char *s, char *a, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	if (a)
	{
		i = 0;
		while (a[i])
		{
			write(fd, &a[i], 1);
			i++;
		}
	}
	write(2, "\n", 1);
}

int exec(char *av[], int i, int tmp_fd, char **env)
{
    av[i] = NULL;
	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
	execve(av[0], av, env);
	ft_putstr_fd("error: cannot execute ", av[0], 2);
	return (1);
}

int	main(int ac, char **av, char **ep)
{
	int	i;
	int	tmp_fd;
	int	fd[2];

	i = 0;
	tmp_fd = dup(0);
	while (av[i] && av[i + 1])
	{
		av = &av[i + 1];
		i = 0;
		while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
			i++;
		if (i != 0 && (!av[i] || !strcmp(av[i], ";")))
		{
			if (!fork())
			{
			}
			else
			{
			}
		}
        else if (av[i] && strcmp(av[i], "|"))
        {
            pipe(fd);
            if (!fork())
			{
			}
			else
			{
			}
        }
	}
}
