#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
    }
    else if (pid == 0) {
      
        sleep(5);
        printf("Child: PID = %d, Parent PID = %d\n",
               getpid(), getppid());
    }
    else {
       
        printf("Parent: PID = %d\n", getpid());
        sleep(10);

      
    }

    return 0;
}