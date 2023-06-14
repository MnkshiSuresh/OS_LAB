#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main(){
    void *shared_mem1;
    char a[100];
    int shmid;
    shmid=shmget((key_t)200,300,0666|IPC_CREAT);
    printf("memory id:%d\n",shmid);
    shared_mem1=shmat(shmid,NULL,0);
    printf("process attached at %p\n",shared_mem1);
    printf("enter the first part of the password:\n");
    read(0,a,100);
    strcpy(shared_mem1,a);
    
    
    void *shared_mem2;
    char b[100];
    int shmid1;
    shmid1=shmget((key_t)201,300,0666|IPC_CREAT);
    printf("memory id:%d\n",shmid1);
    shared_mem2=shmat(shmid1,NULL,0);
    printf("process attached at %p\n",shared_mem2);
    printf("enter the second part of the password:\n");
    read(0,b,100);
    strcpy(shared_mem2,b);
    
    
    void *shared_mem3;
    char c[100];
    int shmid2;
    shmid2=shmget((key_t)202,300,0666|IPC_CREAT);
    printf("memory id:%d\n",shmid2);
    shared_mem3=shmat(shmid2,NULL,0);
    printf("process attached at %p\n",shared_mem3);
    printf("enter the amount deposited:\n");
    read(0,c,100);
    strcpy(shared_mem3,c);
    
    
    return 0;
}