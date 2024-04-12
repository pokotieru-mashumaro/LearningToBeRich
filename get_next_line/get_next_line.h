#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

char	*ft_strjoin(char *left_str, char *buff);
int ft_strlen(char *s);
#endif