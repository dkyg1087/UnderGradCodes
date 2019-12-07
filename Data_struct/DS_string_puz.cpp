#include<iostream>
#include<cstring>
#include<stdlib.h>
int main(){
    int size,targn;
    std::cin>>size>>targn;
    char a[20][20];
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            a[i][j]='#';
        }
    }
    for(int i=1;i<=size;i++){
        for(int j=1;j<=size;j++){
            std::cin>>a[i][j];
        }
    }
}