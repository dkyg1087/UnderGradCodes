#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
float det(int x,int a[][3]);
int main(){
    int arr[3][3]={{2,1,-3},//     |2  1 -3|     |x|  |0|
                   {6,3,-8},//     |6  3 -8|  X  |y| =|0| 
                   {2,-1,5}};//    |2 -1  5|     |z|  |-4|
    float x=.0,y=.0,z=.0;
    x=det(0,arr)/det(3,arr);
    y=det(1,arr)/det(3,arr);
    z=det(2,arr)/det(3,arr);
    cout<<"    "<<x<<endl;
    cout<<"x = "<<y<<endl;
    cout<<"    "<<z<<endl;
    cin.get();//當作system pause用
    return 0;
}
float det(int x,int b[][3]){
    int a[3][3]={};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            a[i][j]=b[i][j];
        }
    }//使我在替換陣列值時不會動到原本陣列
    for(int i=0;i<3;i++){
        if(x==3)break;
        if(i==0||i==1){
            a[i][x]=0;
        }
        else{
            a[i][x]=-4;
        }
    }//將某一個column換成004
    float deter;
    deter=(a[0][0]*a[1][1]*a[2][2])+(a[1][0]*a[2][1]*a[0][2])+(a[0][1]*a[1][2]*a[2][0])-(a[0][2]*a[1][1]*a[2][0])-(a[0][0]*a[2][1]*a[1][2])-(a[1][0]*a[0][1]*a[2][2]);
    return deter; 
}