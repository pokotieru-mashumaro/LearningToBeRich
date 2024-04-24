#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

static void f(int sig)
{
    (void) sig;
    printf("client finish\n");
    exit(0);
}

static void send_to_server(int server_pid, char c)
{
    int i;

    i = 0;
    while (i < 8)
    {
        if (c & (1 << i))
            kill(server_pid, SIGUSR2);
        else
            kill(server_pid, SIGUSR1);
        usleep(1500);
        i++;
    }
}

int main(int ac, char **av)
{
    int server_pid;
    char *str;
    int i;

    if (ac != 3)
        return 0;
    server_pid = atoi(av[1]);
    str = av[2];
    i = 0;
    signal(SIGUSR1, f);
    signal(SIGUSR2, f);
    while (str[i])
    {
        send_to_server(server_pid, str[i]);
        i++;
    }
    send_to_server(server_pid, '\0');
    while (1)
        pause();
    return 0;
}