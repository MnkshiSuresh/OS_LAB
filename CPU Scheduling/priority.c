// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

int main(){
    int i,j,n,bt[10],compl[10],tt[10],wt[10],p[10],temp1,temp2,totttime=0,totwtime=0;
    printf("enter the number of processes:\n");
    scanf("%d",&n);
    printf("enter the burst time and priorities:\n");
    for(i=0;i<n;i++){
        printf("P%d btime:\n",i+1);
        scanf("%d",&bt[i]);
        printf("P%d priority:\n",i+1);
        scanf("%d",&p[i]);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(p[j]<p[i]){
                temp1=p[i];
                p[i]=p[j];
                p[j]=temp1;
                temp2=bt[i];
                bt[i]=bt[j];
                bt[j]=temp2;
            }
        }
    }
    wt[0]=0;
    compl[0]=bt[0];
    for(i=0;i<n;i++){
        compl[i]=bt[i]+compl[i-1];
    }
    for(i=0;i<n;i++){
        tt[i]=compl[i];
        wt[i]=tt[i]-bt[i];
        totttime+=tt[i];
        totwtime+=wt[i];
    }
    printf("TOTAL WAITING TIME:%d\n",totwtime);
    printf("AVERAGE WAITING TIME:%d\n",totwtime/n);
    printf("TOTAL TURNAROUND TIME:%d\n",totttime);
    printf("AVERAGE TURNAROUND TIME:%d\n",totttime/n);
    return 0;
}
