#include "get_next_line.h"

// #define BUFFER_SIZE 1

int find_newline(char *s)
{
	if (!s)
		return 0;
	while (*s)
	{
		if (*s == '\n')
			return 1;
		s++;
	}
	return 0;
}

char *get_line(int fd, char *last_str)
{
	char *buff;
	int buffer_bytes;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	while (!find_newline(last_str) && (buffer_bytes = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[buffer_bytes] = '\0';
		last_str = ft_strjoin(last_str, buff);
	}
	free(buff);
	if (buffer_bytes == -1)
			return (NULL);
	return (last_str);
}

char *cut_over_newline(char *last_str)
{
	int i;
	char *ret;
	char *ret_original;

	i = 0;
	if (!last_str[i])
		return (NULL);
	while (last_str[i] && last_str[i] != '\n')
		i++;
	ret = (char *)malloc(i + 2);
	ret_original = ret; 
	while (*last_str && *last_str != '\n')
		*ret++ = *last_str++;
	if (*last_str == '\n')
		*ret++ = '\n';
	*ret = '\0';
	return ret_original;
}

char *cut_left_on_laststr(char *last_str)
{
	int i;
	int j;
	char *ret;

	i = 0;
	while (last_str[i] && last_str[i] != '\n')
		i++;
	if (!last_str[i])
	{
		free(last_str);
		return (NULL);
	}
	i++;
	ret = (char *)malloc(ft_strlen(last_str) - i + 1);
	j = 0;
	while (last_str[i])
		ret[j++] = last_str[i++];
	ret[j] = '\0';
	free(last_str);
	return ret;
}

char *get_next_line(int fd)
{
	char *ret;
	static char *last_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	last_str = get_line(fd, last_str);
	if (!last_str)
		return (NULL);
	ret = cut_over_newline(last_str);
	last_str = cut_left_on_laststr(last_str);
	return (ret);
}

// int main(int ac, char *av[])
// {
// 	int fd;
// 	int i;
// 	char *pri;

// 	fd = open((char *)av[1], O_RDONLY);
// 	i = 0;
// 	while (i < 100)
// 	{
// 		pri = get_next_line(fd);
// 		printf("%s", pri);
// 		free(pri);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }