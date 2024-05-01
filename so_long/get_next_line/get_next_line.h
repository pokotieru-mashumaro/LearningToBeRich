#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char *get_next_line(int fd);

char *concat_two_str(char *s1, char *s2);
int ft_strlen(char *s);

#endif