#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static void f(int a)
{

}

void send_to_server(int pid, char c)
{
  char a;
  char b;
  int i;

  i = 0;
  while (i < 8)
  {
    if (c & (1 << i))
        kill(pid, SIGUSR2);
    else
        kill(pid, SIGUSR1);
    i++;
  }
}

int main(int ac, char **av)
{
    int pid;
    char *str;
    int i;

    if (ac != 3)
        return 0;
    pid = atoi(av[1]);
    str = av[2];
    i = 0;
    // signal(SIGUSR1, f);
	// signal(SIGUSR2, f);
    while (str[i])
    {
        send_to_server(pid, str[i]);
        i++;   
    }
    return 0;
}