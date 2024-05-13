#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <stdbool.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <termios.h>
#include <sys/ioctl.h>

void ft_putstr_fd(char *s, int fd);
char *get_next_line(int fd);
int ft_strlen(char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif