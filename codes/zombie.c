#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid == 0)
    {
        printf("Child: PID = %ld, exiting now.\n", (long)getpid());
        exit(0);
    }
    else
    {
        printf("Parent: PID = %ld\n", (long)getpid());
        printf("Check child %ld in another terminal.\n", (long)pid);

        sleep(30);

        wait(NULL);
        printf("Parent collected child status. Zombie removed.\n");
    }

    return 0;
}