#include<stdio.h>
#include<stdlib.h>
int main(){
    int size,i,j,count;
    scanf("%d",&size);
    int** arr=calloc(size,sizeof(int*));
    for(int i=0;i<size;i++)arr[i]=calloc(size,sizeof(int));
    for(i=0;i<size;i++)for(j=0;j<size;j++)arr[i][j]=0;
    arr[0][size/2]=1;
    for(count=2,i=0,j=size/2;count<(size*size)+1;count++){
        i--,j++;
        if(i<0)i=size-1;
        if(j>=size)j=0;
        if(arr[i][j]!=0){
            i+=2,j--;
            if(i<0)i+=size;
            if(i>=size)i-=size;
            if(j<0)j+=size;
            if(j>=size)i-=size;
            arr[i][j]=count;
        }
        else{
            arr[i][j]=count;
        }
    }
    for(i=0;i<size;i++){
        printf("%d",arr[i][0]);
        for(j=1;j<size;j++){
            printf(" %d",arr[i][j]);
        }
        printf("\n");
    }
}