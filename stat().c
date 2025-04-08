#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(){
    char filename[100];
    struct stat filestat;
    printf("\nenter the file name");
    scanf("%s",filename);
    if(stat(filename,&filestat)==-1){
        perror("statb failed");
        exit(1);
    }
    printf("\nfile %s\n",filename);
    printf("no of links %ld\n",(long)filestat.st_nlink);
    printf("\npermission %o",filestat.st_mode);
    printf("\nuser id %ld",(long)filestat.st_uid);
}
