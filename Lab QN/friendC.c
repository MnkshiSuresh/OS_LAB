#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main(){
    void *shared_mem2;
    char b[100];
    int shmid1;
    shmid1=shmget((key_t)201,300,0666|IPC_CREAT);
    printf("memory id:%d\n",shmid1);
    shared_mem2=shmat(shmid1,NULL,0);
    printf("process attached at %p\n",shared_mem2);
    printf("second part password:%s\n",(char *)shared_mem2);
    
    
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