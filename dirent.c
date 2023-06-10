//opendir(),closedir(),readdir()


#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
struct dirent *dptr;
int main(){
    DIR *dirp;
    char buff[200];
    printf("enter the name of directory:\n");
    scanf("%s",buff);
    if((dirp=opendir(buff))==NULL){
        printf("error");
        exit(1);
    }
    while(dptr=readdir(dirp)){
        printf("%s\n",dptr->d_name);
    }
    closedir(dirp);
    return 0;
}
