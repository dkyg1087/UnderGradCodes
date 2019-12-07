#include<stdio.h>
#include<stdlib.h>
int main(){
    int amount,i;
    scanf("%d\n",&amount);
    int* arr=calloc(amount,sizeof(int));
    for(i=0;i<amount;i++){
        scanf("%d",&arr[i]);
    }
    int j,k;
    for(j=0;j<amount;j++){
        int min=arr[j],it=j;
        for(k=j;k<amount;k++){
            if(arr[k]<arr[j]){
                min=arr[k];
                it=j;
            }
        }
        int temp;
        temp=arr[j];
        arr[j]=arr[it];
        arr[it]=temp;
    }
    printf("%d",arr[0]);
    for(i=1;i<amount;i++){
        printf(" %d",arr[i]);
    }
    printf("\n");
}