#include<stdio.h>
#include<stdlib.h>
int main(){
    int amount,i,j,max=0;
    scanf("%d",&amount);
    int* arr=calloc(amount,sizeof(int));
    for(i=0;i<amount;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<amount;i++){
        for(j=i+2;j<amount;j++){
            if((arr[i]+arr[j])>max)max=arr[i]+arr[j];
        }
    }
    printf("%d\n",max);
    return 0;
}