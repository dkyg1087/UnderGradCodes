#include<stdio.h>
#include<stdlib.h>
void add(int *arr,int n,int amount,int space){
    int i,j,k;
    for(i=0;i<amount;i++){
        if(arr[i]==2)break;
    }
    if(space==0){
        for(j=n;j>0;j--,i++){
            arr[i]=1;
        }
        arr[i]=0;
        return;
    }
    for(j=n,k=space;j>0;j--,i++,k--){
        if(k>0)arr[i]=0;
        else arr[i]=1;
    }
    for(j=0;j<space;j++,i++)arr[i]=0;
}
int main(){
    int amount,x,space,i=0,sum=0;
    scanf("%d",&amount);
    int* arr=calloc(amount,sizeof(int));
    int* blk=calloc(amount,sizeof(int));
    for(x=0;x<amount;x++)arr[x]=2;
    while(scanf("%d",&x)!=EOF){
        blk[i]=x;
        sum+=x;
        i++;
    }
    space=(amount-sum)-(i-1);
    for(x=0;x<i;x++){
        add(arr,blk[x],amount,space);
    }
    printf("%d",arr[0]);
    for(x=1;x<amount;x++){
        printf(" %d",arr[x]);
    }
    printf("\n");
}