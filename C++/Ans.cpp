#include<stdio.h>
int main(){
    int a[7][7]={},total=0;
    double avg;
    int i=0,j=0;
    for(;i<7;i++){
        for(;j<7;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(;i<7;i++){
        for(;j<7;j++){
           printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}