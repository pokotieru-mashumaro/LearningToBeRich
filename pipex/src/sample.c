#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

static void child()
{
    char *args[] = {"/bin/echo", "こんにちは", NULL};
    printf("child. child's pid: %d.\n", getpid());
    execve("/bin/echo", args, NULL);
    err(EXIT_FAILURE, "execve() failed");
}

static void parent(pid_t pid_child)
{
    printf("parent. parent's pid: %d. child's pid: %d\n", getpid(), pid_child);
    exit(EXIT_SUCCESS);
}


int main(void)
{
    pid_t pid;
    pid = fork();
    if(pid == -1)
        err(EXIT_FAILURE, "fork() failed");

    if(pid == 0)
        child();
    else
        parent(pid);

}
