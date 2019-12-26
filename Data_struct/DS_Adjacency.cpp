#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int arr[1024][1024];
int main(){
    int num1,num2,maxx=0;
    for(int i=0;i<1024;i++){
        for(int j=0;j<1024;j++){
            arr[i][j]=0;
        }
    }
    while (cin>>num1>>num2){
        if(maxx<max(num1,num2))maxx=max(num1,num2);
        arr[num1][num2]=1;
        arr[num2][num1]=1;
    }
    cout<<"Adjacency matrix:"<<endl;
    for(int i=0;i<=maxx;i++){
        cout<<arr[i][0];
        for(int j=1;j<=maxx;j++){
            cout<<" "<<arr[i][j];
        }
        cout<<endl;
    }
    cout<<endl<<"Adjacency list:"<<endl;
    for(int i=0;i<=maxx;i++){
        cout<<i<<":";
        for(int j=0;j<=maxx;j++){
            if(arr[i][j]==1){
                cout<<" "<<j<<" ->";
            }
        }
        cout<<" end"<<endl;
    }
    return 0;
}