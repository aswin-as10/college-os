#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
struct dirent *dptr;
int main(){
    DIR *dirp;
    char buffer[100];
    printf("enter the directory name");
    scanf("%s",buffer);
    if((dirp=opendir(buffer))==NULL){
        printf("given directory does not exist");
        exit(1);
    }
    while((dptr=readdir(dirp))!=NULL){
        printf("%s\n",dptr->d_name);
    }
    closedir(dirp);
}
