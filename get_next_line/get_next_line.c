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

char *get_line(int fd, char *stock_str)
{
	char *buf;
	int n;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!find_newline(stock_str))
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n <= 0)
			break;
		buf[n] = '\0';
		stock_str = concat_two_str(stock_str, buf);
	}
	free(buf);
	if (n == -1)
		return (NULL);
	return (stock_str);
}

char *cut_over_newline(char *stock_str)
{
	int i;
	char *ret;
	char *ret_original;

	if (stock_str[0] == '\0')
		return (NULL);
	i = 0;
	while (stock_str[i] && stock_str[i] != '\n')
		i++;
	ret = (char *)malloc(i + 2);
	if (!ret)
		return NULL;
	ret_original = ret; 
	while (*stock_str && *stock_str != '\n')
		*ret++ = *stock_str++;
	if (*stock_str == '\n')
		*ret++ = '\n';
	*ret = '\0';
	return ret_original;
}

char *cut_left_on_laststr(char *stock_str)
{
	int i;
	int j;
	char *ret;

	i = 0;
	while (stock_str[i] != '\n')
	{
		if (!stock_str[i])
		{
			free(stock_str);
			return (NULL);
		}
		i++;
	}
	i++;
	ret = (char *)malloc(ft_strlen(stock_str) - i + 1);
	j = 0;
	while (stock_str[i])
		ret[j++] = stock_str[i++];
	ret[j] = '\0';
	free(stock_str);
	return ret;
}

char *get_next_line(int fd)
{
	char *ret;
	static char *stock_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock_str = get_line(fd, stock_str);
	if (!stock_str)
		return (NULL);
	ret = cut_over_newline(stock_str);
	stock_str = cut_left_on_laststr(stock_str);
	return (ret);
}

// int main(int ac, char *av[])
// {
// 	int fd;
// 	int i;
// 	char *pri;
// 	(void) ac;

// 	fd = open((char *)av[1], O_RDONLY);
// 	i = 0;
// 	while (i < 10)
// 	{
// 		pri = get_next_line(fd);
// 		printf("line%d: %s", i+1, pri);
// 		free(pri);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }