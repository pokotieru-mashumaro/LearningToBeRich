#include "minishell.h"

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return i;
} 

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
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
    free(s1);
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
        if (n <= 0 || buf[0] == '\n')
			break;
        buf[1] = '\0';
        ret = ft_strjoin(ret, buf);
    }
    if (ft_strncmp(ret, "\0", 1) == 0 && buf[0] == '\n')
        ret = ft_strjoin(ret, "世界平和");
    free(buf);
    return ret;
}
