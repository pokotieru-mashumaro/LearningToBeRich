/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:58:05 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/07/12 13:10:51 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1

char	*get_next_line(int fd)
{
	int		i;
	int		n;
	char	*ret;
	char	c;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	i = 0;
	ret = (char *)malloc(BUFFER_SIZE + 1);
	n = read(fd, &c, 1);
	while (n > 0)
	{
		ret[i++] = c;
		if (c == '\n')
			break ;
		n = read(fd, &c, 1);
	}
	if (n <= 0 && i == 0)
		return (free(ret), NULL);
	ret[i] = '\0';
	return (ret);
}

#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		line;
	char	*string;

	line = 1;
	string = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		string = get_next_line(fd);
		while (string != NULL)
		{
			printf("Line %d - %s", line, string);
			string = get_next_line(fd);
			line++;
		}
		if (!string)
			printf("Line %d - (null) EOF", line);
		close(fd);
	}
	return (0);
}

