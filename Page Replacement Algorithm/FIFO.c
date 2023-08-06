//FIFO 1

#include<stdio.h>
#define MAX_FRAMES 3

int fifo(int pages[],int n,int capacity){
    int pagefaults=0;
    int pagetable[MAX_FRAMES];
    int front=0,rear=-1;
    for(int i=0;i<MAX_FRAMES;i++){
        pagetable[i]=-1;
    }
    
    for(int i=0;i<n;i++){
       int currentpage=pages[i];
       int pagefound=0;
       for(int j=0;j<capacity;j++){
           if(pagetable[j]==currentpage){
               pagefaults=1;
               break;
           }
       }
       if(pagefound==0){
           pagefaults++;
           rear=(rear+1)%capacity;
           pagetable[rear]=currentpage;
           if(front=rear){
               front=(front+1)%capacity;
           }
       }
    }
    return pagefaults;
}
void main(){
    int pages[]={1,2,3,4,1,2,5,1,2,3,4,5};
    int n=sizeof(pages)/sizeof(pages[0]);
    int capacity=3;
    int pagefaults=fifo(pages,n,capacity);
    printf("The total pagesfaults found: %d",pagefaults);
}









//FIFO 2

#include<stdio.h> 
void main() {
 int i, j, k, f, pf=0, count=0, rs[25], m[10], n; 
 printf("\n Enter the length of reference string -- "); 
 scanf("%d",&n); printf("\n Enter the reference string -- "); 
 for(i=0;i<n;i++) scanf("%d",&rs[i]); 
 printf("\n Enter no. of frames -- "); 
 scanf("%d",&f); 
 for(i=0;i<f;i++) m[i]=-1;
 printf("\n The Page Replacement Process is -- \n");
 for(i=0;i<n;i++) 
 { 
 for(k=0;k<f;k++) 
 { 
 if(m[k]==rs[i]) 
 break; 
  } 
 if(k==f) 
 { 
 m[count++]=rs[i];
 pf++; 
  } 
 for(j=0;j<f;j++)
 printf("\t%d",m[j]); 
 if(k==f) 
 printf("\tPF No. %d",pf); 
 printf("\n"); 
 if(count==f) count=0; } 
 printf("\n The number of Page Faults using FIFO are %d",pf); }