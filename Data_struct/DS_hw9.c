#include<stdio.h>
#include<stdlib.h>
typedef struct{
    float bot;
    int top;
}poly;
int main(){
    int x,i;
    scanf("%d",&x);
    poly* arr=calloc(x,sizeof(poly));
    for(i=0;i<x;i++)scanf("%f %d",&arr[i].bot,&arr[i].top);
    if(arr[0].top==0){
        printf("%f\n",arr[0].bot);
        goto StartB ; 
    }
    else if(arr[0].bot<0)printf("-%fx^%d",arr[0].bot,arr[0].top);
    else printf("%fx^%d",arr[0].bot,arr[0].top);
    for(i=1;i<x-1;i++){
        if(arr[i].bot>0)printf("+%fx^%d",arr[i].bot,arr[i].top);
        else printf("%fx^%d",arr[i].bot,arr[i].top);
    }
    if(arr[x-1].top==0)printf("%f\n",arr[x-1].bot);
    else if(arr[x-1].bot>0)printf("+%fx^%d\n",arr[x-1].bot,arr[x-1].top);
    else printf("%fx^%d\n",arr[x-1].bot,arr[x-1].top);
    StartB:
    int y;
    scanf("%d",&y);
    poly* r_arr=calloc(x+y,sizeof(poly));
    for(i=0;i<x;i++){
        r_arr[i].top=arr[i].top;
        r_arr[i].bot=arr[i].bot;
    }
    
}
void print(poly x,int y){
    if(y==1){
        if(x.top==0)printf("%f",x.bot);
        else printf("%fx^%d",x.bot,x.top);
    }
    else{
        
    }
}
