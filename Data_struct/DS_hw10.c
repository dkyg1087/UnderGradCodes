#include<stdio.h>
#include<stdlib.h>
int main(){
    int row,col,i,j,Zero=0,nZero=0;
    scanf("%d %d",&row,&col);
    int** arr=calloc(row,sizeof(int*));
    for(i=0;i<col;i++){
        arr[i]=calloc(col,sizeof(int));
    }
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==0)Zero++;
            else nZero++;
        }
    }
    printf("%d %d %d\n",row,col,nZero);
    if(Zero<(row*col*2/3)){
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                printf("%d ",arr[i][j]);
            }
            printf("\n");
        }
    }
    else{
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(arr[i][j]!=0){
                    printf("%d %d %d\n",i,j,arr[i][j]);
                }
            }
        }
    }
}