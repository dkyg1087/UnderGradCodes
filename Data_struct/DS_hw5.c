#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int main(){
    int amount,i;
    scanf("%d",&amount);
    int* arr=calloc(amount+2,sizeof(int));
    for(i=0;i<amount+2;i++)arr[i]=0;
    arr[0]=INT_MIN;
    arr[amount+1]=INT_MAX;
    scanf("%d",&arr[1]);
    int num,k;
    for(i=0;i<(amount-1);i++){
        scanf("%d",&num);
        for(k=1;k<=amount;k++){
            if(arr[k-1]<num&&arr[k]>num){
                int j;
                for(j=amount;k!=j;j--){
                    arr[j]=arr[j-1];
                }
                arr[k]=num;
                break;
            }
            else if(arr[k]<num&&arr[k+1]==0){
                arr[k+1]=num;
                break;
            }
        }
        if(i<=1){
            printf("%d",arr[1]);
            int count;
            for(count=2;count<i+3;count++){
                printf(" %d",arr[count]);
            }
            printf("\n");
        }
    }
    printf("%d",arr[1]);
    for(i=2;i<=amount;i++){
        printf(" %d",arr[i]);
    }
    printf("\n");
}