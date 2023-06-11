//BEST FIT

#include<stdio.h>
void firstfit(int p[],int pno,int b[],int bno){
    int i,j;
    int allo[pno];
    int occu[bno];
    for(i=0;i<pno;i++){
        allo[i]=-1;
    }
    for(i=0;i<bno;i++){
        occu[i]=0;
    }
    
    for(i=0;i<pno;i++){
        int index=-1;
        for(j=0;j<bno;j++){
            if(!occu[j] && b[j]>=p[i]){
            if(index==-1){
                index=j;
            }else if(b[j]<b[index]){
                index=j;
            }
                }
        }
          if(index!=-1){
              allo[i]=index;
              occu[index]=1;
          }  
        
                
        }
        
    printf("\nPROCESS NO\t\t\tPROCESS SIZE\t\t\tBLOCK NO\n");
    for(i=0;i<pno;i++){
        printf("%d\t\t\t%d\t\t\t",i+1,p[i]);
       if(allo[i]!=-1)
           printf("%d\n",allo[i]+1);
           else
           printf("not alloc\n");
       }
    
    }

int main() {
   int pno,bno;
   printf("enter the no of processes:\n");
   scanf("%d",&pno);
   printf("enter the no of blocks:\n");
   scanf("%d",&bno);
   int p[pno];
   int b[bno];
   printf("enter the size of processes:\n");
   for(int i=0;i<pno;i++){
       printf("P%d:",i);
       scanf("%d",&p[i]);
   }
   printf("enter the size of blocks:\n");
   for(int i=0;i<bno;i++){
       printf("B%d:",i);
       scanf("%d",&b[i]);
   }
   firstfit(p,pno,b,bno);
   return 0;
}