#include <stdio.h>


int main(){
    FILE *f;
    f=fopen("code.txt","r");
    if(f){
    int c;
    // char p[23];
    // printf("enter your name: ");
    // fgets(p, sizeof(p), stdin);
    // fputs(p, f);
    // printf("enter another name: ");
    // fgets(p, sizeof(p), stdin);
    // fputs(p, f);
    // printf("enter their name: ");
    // fgets(p, sizeof(p), stdin);
    // fputs(p, f);
    while((c=fgetc(f))!=EOF){
        printf("%c",c);
    }
    

    fclose(f);
    }
    
}