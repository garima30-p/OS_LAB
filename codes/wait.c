#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>


//write a program to find sum of elements in an array within child process, and then check whether given sum is prime or not in the parent process
//write a program to read string from the user within child process and then print all the permutations of characters of the given string
bool prime(int num){
    if(num<2) return false;
    for(int i=2;i<=num/2;i++){
        if(num%i==0) return false;
    }
    return true;
}


int sum(int arr[],int n){
    int s=0;
    for(int i=0;i<n;i++){
        s+=arr[i];
    }
    return s;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int num;
    int pid=fork();
    
    if(pid<0){
        printf("failed");
    }
    else if(pid==0){
        num=sum(arr,n);
        printf("the sum of the elements of the array is: %d", num);
    }
    else{
        wait(NULL);
        if(prime(num)) printf("sum is prime.");
        else printf("sum is not prime.");
    }


}