#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
int search(char** arr,std::string c_arr,int dir,int i,int j,int size){
    int k,count;
    for(count=k=0;count<c_arr.size();count++){
        switch (dir){
            case 1:
                if(arr[i-count<0?i-count+size:i-count][j]!=c_arr[count])return 0;
                break;
            case 2:
                if(arr[i][j+count>size?j+count-size:j+count]!=c_arr[count])return 0;
                break;
            case 3:
                if(arr[i+count>size?i+count-size:i+count][j]!=c_arr[count])return 0;
                break;
            case 4:
                if(arr[i][j-count<0?j-count+size:j-count]!=c_arr[count])return 0;
                break;
        }
    }
    return 1;
}
int main(){
    int size,targn,i,j;
    scanf("%d %d",&size,&targn);
    char** arr=new char*[size];
    for(i=0;i<size;i++)arr[i]=new char[size];
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            scanf("%c",&arr[i][j]);
            if(arr[i][j]=='\n'){
                scanf("%c",&arr[i][j]);
            }
        }
    }
    std::string c_arr;
    std::cin.get();
    for(;targn>0;targn--){
        cin>>c_arr;
        int flag=0;
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                if(arr[i][j]==c_arr[0]){
                    if(arr[i-1<0?i-1+size:i-1][j]==c_arr[1])flag+=search(arr,c_arr,1,i,j,size);
                    if(arr[i+1>size?i+1-size:i+1][j]==c_arr[1])flag+=search(arr,c_arr,3,i,j,size);
                    if(arr[i][j+1>size?j+1-size:j+1]==c_arr[1])flag+=search(arr,c_arr,2,i,j,size);
                    if(arr[i][j-1<0?j-1+size:j-1]==c_arr[1])flag+=search(arr,c_arr,4,i,j,size);
                if(flag>=1)goto Ans;
                }
            }
        }
        Ans:
        if(flag==0)printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}