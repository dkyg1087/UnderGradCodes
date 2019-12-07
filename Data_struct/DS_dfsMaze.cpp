#include<stdio.h>
#include<iostream>
bool search(char arr[][10],int i,int j){
    if(arr[i][j]=='1')return false;
    else if(arr[i][j]=='X')return true;
    else if(arr[i][j]=='0')arr[i][j]='G';
    else if(arr[i][j]=='G')return false;
    if(search(arr,i,j+1)||search(arr,i-1,j)||search(arr,i,j-1)||search(arr,i+1,j)){
        return true;
    }
    else return false;
}
int main(){
    char arr[10][10],junk;
    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            std::cin>>arr[i][j];
        }
    }
    arr[1][1]='X';
    arr[8][8]='S';
    if(search(arr,8,8)){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    for(i=0;i<10;i++){
        printf("%c",arr[i][0]);
        for(j=1;j<10;j++){
            printf(" %c",arr[i][j]);
        }   
        printf("\n");
    }
}