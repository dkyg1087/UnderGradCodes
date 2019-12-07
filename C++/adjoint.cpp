#include<iostream>
using namespace std;
float deter(int a[][3]);
int main(){
    int arr[3][3]={22,11,2, //反方陣為 1 -3  7
                   14,13,3, //       -5 16 -38
                    3, 4,1};//       17 -55 132
    int Adj[3][3]={};
    /*以下是設定adjoint以及直接transpose*/
    Adj[0][0]= (arr[1][1]*arr[2][2])-(arr[1][2]*arr[2][1]);
    Adj[1][0]=-1*((arr[1][0]*arr[2][2])-(arr[1][2]*arr[2][0]));
    Adj[2][0]= (arr[1][0]*arr[2][1])-(arr[1][1]*arr[2][0]);
    Adj[0][1]=-1*((arr[0][1]*arr[2][2])-(arr[0][2]*arr[2][1]));
    Adj[1][1]= (arr[0][0]*arr[2][2])-(arr[0][2]*arr[2][0]);
    Adj[2][1]=-1*((arr[0][0]*arr[2][1])-(arr[0][1]*arr[2][0]));
    Adj[0][2]= (arr[0][1]*arr[1][2])-(arr[0][2]*arr[1][1]);
    Adj[1][2]=-1*((arr[0][0]*arr[1][2])-(arr[0][2]*arr[1][0]));
    Adj[2][2]= (arr[0][0]*arr[1][1])-(arr[0][1]*arr[1][0]);
    cout<<"The inverse is :"<<endl;
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            Adj[i][j]=Adj[i][j]/deter(arr);
            cout<<Adj[i][j]<<" ";
            if(j==2){
                cout<<endl;
            }
        }
    }
    cin.get();//做到system pause 的效果
    return 0;
}
float deter(int a[][3]){//算det(arr)
    return (a[0][0]*a[1][1]*a[2][2])+(a[1][0]*a[2][1]*a[0][2])+(a[0][1]*a[1][2]*a[2][0])-(a[0][2]*a[1][1]*a[2][0])-(a[0][0]*a[2][1]*a[1][2])-(a[1][0]*a[0][1]*a[2][2]);
}