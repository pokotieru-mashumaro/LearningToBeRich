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
#include <readline/readline.h>
#include <readline/history.h>

#include "libft/libft.h"

#define STDERR 2
#define MINISHELL "\x1b[33mMINISHELL$\x1b[m "

void minishell(char **envp);
void sig_int_input();
void sig_quit_input();

char *get_next_line(int fd);

#endif