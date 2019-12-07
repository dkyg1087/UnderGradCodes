#include<stdio.h>
#include<stdlib.h>
int main(){
    int goal,amount,i;
    scanf("%d",&goal);
    scanf("%d",&amount);
    int* arr=calloc(amount,sizeof(int));
    for(i=0;i<amount;i++){
        scanf("%d",&arr[i]);
    }
    int flag=1,mid,left=0,right=amount-1,ans;
    while(flag!=0){
        mid=(left+right)/2;
        if(goal<arr[mid])right=mid-1;
        else if(goal>arr[mid])left=mid+1;
        else{
            ans=mid;
            flag=0;
        }
    }
    printf("%d\n",ans);
}