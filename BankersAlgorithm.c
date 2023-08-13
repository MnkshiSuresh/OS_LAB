//Deadlock and Bankers Algorithm problem

#include<stdio.h>
#include<stdlib.h>
void main(){
    int n,r,i,j,k,y,flag,index=0,allocation[10][10],max[10][10],need[10][10],available[10],finish[10],order[10];
    printf("BANKERS ALGORITHM \n");
    printf("Enter The Number Of Processes ");
    scanf("%d",&n);
    printf("Enter The Number Of Resources ");
    scanf("%d",&r);
    printf("Enter The Allocation matrix %d x %d",n,r);
    for(i=0;i<n;i++){
        for(j=0;j<r;j++){
            scanf("%d",&allocation[i][j]);
        }
    }
    printf("Enter The Max matrix %d x %d",n,r);
    for(i=0;i<n;i++){
        for(j=0;j<r;j++){
            scanf("%d",&max[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<r;j++){
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    printf("The Need Matrix Is \n");
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<r;j++){
            printf("%d  ",need[i][j]);
        }
    }
    printf("\n");
    
    for(i=0;i<n;i++){
        finish[i]=-1;
    }
    
    printf("Enter The Available Vector ");
    for(i=0;i<r;i++){
        scanf("%d",&available[i]);
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            flag=0;
            if(finish[j]==-1){
                for(k=0;k<r;k++){
                    if(need[j][k]>available[k]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    finish[j]=1;
                    order[index++]=j;
                    for(y=0;y<r;y++){
                        available[y]+=allocation[j][y];
                    }
                }
            }
        }
    }
    int check=0;
    for(i=0;i<n;i++){
        if(finish[i]==-1){
            check=1;
            printf("System Not In Safe State");
            break;
        }
    }
    
    if(check==0){
        printf("System Is In Safe State \n");
        for(i=0;i<n-1;i++){
            printf("%d -> ",order[i]);
        }
        printf("%d",order[n-1]);
    }
}
