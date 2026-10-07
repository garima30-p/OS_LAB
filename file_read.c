#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>

// write a c program to create input.txt in parent process and write your name university and class roll no in it, and then read same file in child process and print the content.

int main(){
    FILE* f;
    
    int p=fork();
    if(p<0){
        printf("fork failed");
        return 1;
    }
    if(p==0){
        f=fopen("input.txt","r");
        if(!f){
            printf("error reading file");
            return 0;

        }
        char buffer[100];
        while(fgets(buffer,sizeof(buffer),f)!=NULL){
            printf("%s",buffer);
        }
        fclose(f);
    }
    else{
    f=fopen("input.txt","w");
    if(f==NULL) return 1;
    char name[59];
    int uni_roll;
    int class_roll;
    printf("write you name: ");
   
    scanf("%s", name);
    
  
   
    scanf("%d",&uni_roll);
   
    scanf("%d",&class_roll);
        fprintf(f,"Name: %s\n",name);
        fprintf(f,"University Roll no: %d\n",uni_roll);
        fprintf(f,"Class Roll no: %d\n",class_roll);
        fclose(f);
        wait(NULL);

    }
}