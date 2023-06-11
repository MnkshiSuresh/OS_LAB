#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main(){
    void *shared_memory;
    char buffer[100];
    int shmid;
    shmid=shmget((key_t)1222,1024,0666);
    printf("Key of the shared memory is %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("Process attached at %p\n",shared_memory);
    printf("Data read from sahred_memory is:%s\n",(char*)shared_memory);
    return 0;
}