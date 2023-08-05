#include<stdlib.h>
#include<stdio.h>
struct fcfs{
    int pid;
    int atime;
    int btime;
    int ctime;
    int wtime;
    int tatime;
}p[10];

void main(){
    int i,n;
    int totwtime=0,totttime=0;
    printf("-------FCFS SCHEDULING---------\n");
    printf("enter the number of processes:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        p[i].pid=i;
        printf("enter the bursttime:\n");
        printf("btime of %d:\n",p[i].pid);
        scanf("%d",&p[i].btime);
        printf("enter the arrivaltime:\n");
        printf("atime of %d:\n",p[i].pid);
        scanf("%d",&p[i].atime);
    }
    p[0].wtime=0;
    p[0].ctime=0;
    for(i=1;i<=n;i++){
     p[i].ctime=p[i].btime+p[i-1].ctime;
     p[i].tatime=p[i].ctime-p[i].atime;
     totttime+=p[i].tatime;
     p[i].wtime=p[i].tatime-p[i].btime;
     totwtime+=p[i].wtime;}
     
     printf("-------------------TABLE-------------------");
     printf("\npid\tatime \tbtime \tctime \ttat \twt \t \n");
      for(i=1;i<=n;i++){
          printf("\n %d \t %d \t %d \t %d \t %d \t %d \t \n",p[i].pid,p[i].atime,p[i].btime,p[i].ctime,p[i].tatime,p[i].wtime);}
          
          printf("\nAverage TurnAroundTime= %d \nAverage WaitingTime=%d \n",totttime/n,totwtime/n);}
