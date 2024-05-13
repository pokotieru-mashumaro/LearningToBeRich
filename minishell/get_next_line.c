#include "minishell.h"

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return i;
} 

char *ft_strdup(char *s1)
{
	int i;
	char *ret;

	i = 0;
	ret = (char *)malloc(ft_strlen(s1) + 1);
	if (!ret)
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return ret;
}

char *ft_strjoin(char *s1, char *s2)
{
    char *ret;
    int i;
	int j;

    if (!s1)
        s1 = ft_strdup("\0");
    ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return NULL;
    i = 0;
    while (s1[i])
	{
        ret[i] = s1[i];
		i++;
	}
	j = 0;
    while (s2[j])
        ret[i++] = s2[j++];
    ret[ft_strlen(s1) + ft_strlen(s2)] = '\0';
    return ret;
}

char *get_next_line(int fd)
{
    char *ret;
    char *buf;
    int n;

    ret = (char *)malloc(1);
    buf = (char *)malloc(2);
    while (1)
    {
        n = read(fd, &buf[0], 1);
        if (n <= 0)
			break;
        buf[1] = '\0';
        ret = ft_strjoin(ret, buf);
    }
    free(buf);
    return ret;
}
