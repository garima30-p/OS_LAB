#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>

int main(){
    int pid=fork();
    if(pid<0){
        printf("failed");
    }
    else if(pid==0){
        sleep(10);
        printf("child process");

        printf("child process id: %d",getppid());
    }
    else{
       
        printf("parent process");
    }
}