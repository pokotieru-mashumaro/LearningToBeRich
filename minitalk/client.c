#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static void f(int a)
{

}

int main(int ac, char **av)
{
    int pid;

    if (ac != 3)
        return 0;
    pid = atoi(av[2]);
    signal(SIGUSR1, f);
	signal(SIGUSR2, f);
    return 0;
}