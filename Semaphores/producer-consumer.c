#include<stdio.h>
#include<stdlib.h>
int mutex=1;
int empty=5;
int x=0;
int full=0;

void producer(){
    --mutex;
    ++full;
    --empty;
    x++;
    printf("\n Producer produces item %d", x);
    ++mutex;
}

void consumer(){
    --mutex;
    --full;
    ++empty;
    printf("\n Consumer consumes the item %d",x);
    x--;
    ++mutex;
}


int main(){
    int n,i;
    printf("1. Press 1 for Producer Process\n2. Press 2 for Consumer Process\n3. Press 3 to Exit\n");
    for(i=1;i>0;i++){
        printf("\nenter your choice\n");
        scanf("%d",&n);
        switch(n){
            case 1:
            
            if((mutex==1)&&(empty!=0)){
                producer();
            }else{
                printf("Buffer is full!");
            }break;
            
            case 2:
            
            if((mutex==1)&&(full!=0)){
                consumer();
            }else{
                printf("Buffer is empty");
            }break;
            
            case 3:
            exit(0);
            break;
        }
    }
}