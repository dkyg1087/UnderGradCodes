#include<iostream>
using namespace std;
int arr[1024];
void _union(int x,int y,int num){
    if(arr[x]>arr[y]){
        int temp=arr[x];
        for(int i=0;i<=num;i++){
            if(arr[i]==temp)arr[i]=arr[y];
        }
    }
    else{
        int temp=arr[y];
        for(int i=0;i<=num;i++){
             if(arr[i]==temp)arr[i]=arr[x];
        }
    }
}
int main(){
    for(int i=0;i<1024;i++)arr[i]=i;
    int num,temp;
    cin>>num;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            cin>>temp;
            if(temp==1){
                _union(i,j,num);
            }
        }
    }
    int flag=0;
    for(int i=0;i<num;i++){
        if(arr[i]!=arr[0]){
            flag=1;
            cout<<"-1"<<endl;
            break;
        }
    }
    if(flag==0)cout<<"1"<<endl;
}