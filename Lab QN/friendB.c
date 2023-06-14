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
    printf("first part password:%s\n",(char *)shared_mem1);
    
    
    void *shared_mem3;
    char c[100];
    int shmid2;
    shmid2=shmget((key_t)202,300,0666|IPC_CREAT);
    printf("memory id:%d\n",shmid2);
    shared_mem3=shmat(shmid2,NULL,0);
    printf("process attached at %p\n",shared_mem3);
    printf("Amount deposited:%s\n",(char *)shared_mem3);
    
    
    return 0;
}