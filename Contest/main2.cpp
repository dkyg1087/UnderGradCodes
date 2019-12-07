#include<iostream>
using namespace std;
int main(){
    int count,n;
    cin>>count;
    for(;count>0;count--){
        cin>>n;
        int arr[10]={0,0,0,0,0,0,0,0,0,0},num,i;
        for(i=0;i<n;i++){
            cin>>num;
            arr[num]++;
        }
        int max=0;
        for(i=0;i<10;i++){
            if(arr[i]>max){
                max=arr[i];
            }
        }
        cout<<max<<endl;
    }
}