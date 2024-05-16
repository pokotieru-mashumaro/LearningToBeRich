#include "minishell.h"

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
