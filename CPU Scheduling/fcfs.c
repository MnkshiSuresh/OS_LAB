#include<stdlib.h>
#include<stdio.h>
struct fcfs{
    int pid;
    int btime;
    int wtime;
    int ttime;
}p[10];

int main(){
    int i,n;
    int totwtime=0,totttime=0;
    printf("-------FCFS SCHEDULING---------");
    printf("enter the number of processes:";
    scanf("%d",&n);
    for(i=0;i<n;i++){
        p[i].pid=1;
        printf("enter the bursttime:\n");
        printf("btime of %d:\n",p[i]);
        scanf("%d",&p[i].btime);
    }
    p[0].wtime=0;
    p[0].ttime=p[0].btime;
    for(i=0;i<n;i++){
        p[i].wtime=p[i-1].wtime + p[i-1]btime;
        p[i].ttime=p[i].wtime+p[i].btime;
        totttime+=p[i].ttime;
        totwtime+=p[i].wtime;
    }
    printf("Total Waiting Time:%d\n",totwtime);
    printf("Average Waiting Time:%d\n",totwtime/n);
    printf("Total Turn Around Time:%d\n",totttime);
    printf("Average Turn Around Time:%d\n",totttime/n);    
}
