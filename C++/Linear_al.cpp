#include<iostream>
#include<stdlib.h>
using namespace std;
void to_one(int x,int y,int arr[][3],int iden[][3]);
void clear(int x,int y,int z,int arr[][3],int iden[][3]);
int main(){
    int arr[3][3]={2,9,4,7,5,2,1,5,2},iden[3][3]={1,0,0,0,1,0,0,0,1},i,j;
    if(arr[0][0]!=1&&arr[0][0]!=0)to_one(0,0,arr,iden);
    if(arr[1][0]!=0)clear(0,1,0,arr,iden);
    if(arr[2][0]!=0)clear(0,2,0,arr,iden);
    if(arr[1][1]!=1&&arr[1][1]!=0)to_one(1,1,arr,iden);
    if(arr[2][1]!=0)clear(1,2,1,arr,iden);
    if(arr[2][2]!=1&&arr[2][2]!=0)to_one(2,2,arr,iden);
    if(arr[1][2]!=0)clear(2,1,2,arr,iden);
    if(arr[0][2]!=0)clear(2,0,2,arr,iden);
    if(arr[0][1]!=0)clear(1,0,1,arr,iden);
    for(j=0;j<=2;j++){
        for(i=0;i<=2;i++){
            cout<<iden[j][i];
            if(i==2)cout<<endl;
        }
    }
    cin.get();
    return 0;
}
void to_one(int x,int y,int arr[][3],int iden[][3]){
    int i;
    for(i=0;i<3;i++){
        arr[x][i]*=(1/arr[x][y]);
        iden[x][i]*=(1/iden[x][y]);
    }
}
void clear(int x,int y,int z,int arr[][3],int iden[][3]){
    int i;
    int a=-1*arr[y][z]/arr[x][z];
    for(i=0;i<3;i++){
        arr[y][i]+=arr[x][i]*a;
        iden[y][i]+=iden[x][i]*a;
    }
}