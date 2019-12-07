#include<stdio.h>
#include<stdlib.h>
int main(){
    int size,order;
    scanf("%d",&size);
    int *arr=calloc(size,sizeof(int));
    int rear=0,front=0;
    for(;;){
        scanf("%d",&order);
        switch (order){
            case 1:{
                rear=(rear+1)%size;
                if(front==rear){
                    printf("FULL\n");
                    rear--;
                    if(rear<0)rear+=size;
                }
                else scanf("%d",&arr[rear]);
                break;
            }
            case 0:{
                if(front==rear){
                    printf("EMPTY\n");
                }
                else {
                    front=(front+1)%size;
                    printf("%d",arr[front]);
                }
                break;
            }
            case -1:
                goto END;
                break;            
        }
    }
    END:
    return 0;
}