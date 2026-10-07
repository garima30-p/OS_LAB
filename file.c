#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>

int main(){
    FILE *F;
    int pid=fork();
    if(pid=0) return 0;
    else if(pid==1){
        F = fopen("practice.txt","r");
        if(!F){
            printf("error");
            return 0;
        }
         char buffer[100];
        while(fgets(buffer,sizeof(buffer),F)!=NULL){
            printf("%s",buffer);
        }
        fclose(F);
    }
    else{
    F=fopen("practice.txt","w");
    if(F==NULL) return 1;
    char name[59];
    int uni_roll;
    int class_roll;
    printf("write you name: ");
   
    scanf("%s", name);
    
  
   
    scanf("%d",&uni_roll);
   
    scanf("%d",&class_roll);
        fprintf(F,"Name: %s\n",name);
        fprintf(F,"University Roll no: %d\n",uni_roll);
        fprintf(F,"Class Roll no: %d\n",class_roll);
        fclose(F);
        wait(NULL);
   

    }
}