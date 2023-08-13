#include<stdio.h>
struct process{
    int pid,AT,BT,CT,WT,TAT,PRI;
} p[10];
void swap(int *b,int *c){
    int temp;
    temp=*b;
    *b=*c;
    *c=temp;
}
void main(){
    int n,i,check_ar=0;
    float totwt=0,tottat=0,avgwt,avgtat;
    printf("PRIORITY SCHEDULING");
    printf("ENTER THE NUMBER OF PROCESSES");
    scanf("%d",&n);
    printf("ENTER THE ARRIVAL TIME BURST TIME AND PRIORITY OF EACH PROCESS \n");
    printf("AT BT PRI \n");
    for(i=1;i<=n;i++){
        scanf("%d%d%d",&p[i].AT,&p[i].BT,&p[i].PRI);
        p[i].pid=i;
    }
    p[0].CT=0;
    p[1].WT=0;
    p[1].CT=p[1].BT-p[1].AT;
    p[1].TAT=p[1].CT-p[1].AT;
    tottat=p[1].CT-p[1].AT;
    int compl_t=p[1].CT;
    for(i=2;i<=n;i++){
        int min=p[i].PRI;
        for(int j=i+1;j<=n;j++){
            if(min>p[j].PRI && p[j].AT<=compl_t ){
                min=p[j].PRI;
                swap(&p[i].pid,&p[j].pid);
                swap(&p[i].AT,&p[j].AT);
                swap(&p[i].BT,&p[j].BT);
                swap(&p[i].PRI,&p[j].PRI);
            }
        }
        p[i].CT=p[i].BT+p[i-1].CT;
       
        p[i].TAT=p[i].CT-p[i].AT;
        tottat+=p[i].TAT;
        p[i].WT=p[i].TAT-p[i].BT;
        totwt+=p[i].WT;
        compl_t+=p[i].AT;
    }
    
    avgwt=totwt/n;
    avgtat=tottat/n;
    
    printf("THE PROCESSES ARE \n");
    printf("ID\tAT\tBT\tCT\tPRI\tWT\tTAT\t \n");
    for(int i=1;i<=n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t \n",p[i].pid,p[i].AT,p[i].BT,p[i].CT,p[i].PRI,p[i].WT,p[i].TAT);
    }
    printf("Avg waiting time is: %f\n",avgwt);
    printf("Avg turn around time is: %f",avgtat);
    
    
}
