#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>
int isprime(int n){
    if(n<=1)
        return 0;
        for(int i=2;i*i<=n;i++){
            if(n%i==0)
                return 0;
        }
        return 1;
}
int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int arr[n];
    
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int fd[2];
    if(pipe(fd)==-1){
        printf("Pipe failed");
        return 1;
    }
    int pid=fork();
    if(pid<0){
        printf("failed");
        return 1;

    }
    else if(pid==0){
       
       // printf("child process");
        int sum;
        read(fd[0],&sum,sizeof(sum));
        if(isprime(sum))
            printf("Sum is prime");
        else
            printf("Sum is not prime");

       
    }
    else{
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        write(fd[1],&sum,sizeof(sum));
         wait(NULL);
    }
    close(fd[0]);
    close(fd[1]);
    
}