#include<stdio.h>
#include<stdlib.h>
struct sjf{
    int pid;
    int btime;
    int wtime;
    int ttime;
}p[10];

int main(){
    int i,n,j;
    struct sjf tmp;
    int totwtime=0,totttime=0;
    printf("-------SJF SCHEDULING------\n");
    printf("enter the no of processes:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter the process ids:P");
        scanf("%d",&p[i].pid);
        printf("enter the burst time:\n");
        scanf("%d",&p[i].btime);
         }
         p[0].wtime=0;
         p[0].ttime=p[0].btime;
         
         //sorting for btime
         
         for(i=0;i<n-1;i++){
             for(j=i+1;j<n;j++){
                 if(p[i].btime>p[j].btime){
                     tmp=p[i];
                     p[i]=p[j];
                     p[j]=tmp;}}}
                     
         for(i=0;i<n;i++){
             p[i].wtime=p[i-1].wtime+p[i-1].btime;
             p[i].ttime=p[i].wtime+p[i].btime;
             totttime+=p[i].ttime;
             totwtime+=p[i].wtime;
         } 
    printf("Total Waiting Time:%d\n",totwtime);
    printf("Average Waiting Time:%d\n",totwtime/n);
    printf("Total Turn Around Time:%d\n",totttime);
    printf("Average Turn Around Time:%d\n",totttime/n);  
    return 0;         
         
}
