#include<iostream>
using namespace std;
int comb(int,int,int,int);
int comb(int,int,int[][34],int,int);
int count1=0,count2=0;
int main(){
    int n,k;
    while(cin>>n>>k){
        int n1,k1,C[34][34]={};
        cin>>n1>>k1;
        if(n<k)cout<<"error"<<endl;
        else {
            comb(n,k,n1,k1);
            cout<<comb(n,k,C,n1,k1)<<" ";
            cout<<count1<<" "<<count2<<endl;
        }
        count1=count2=0;
    }
    return 0;
}
int comb(int n,int k,int n1,int k1){
    if(n==n1&&k==k1)count2++;
    if(n==k||k==0)return 1;
    else return comb(n-1,k,n1,k1)+comb(n-1,k-1,n1,k1);
}
int comb(int n,int k,int C[][34],int n1,int k1){
    if(n==n1&&k==k1)count1++;
    if(C[n][k]!=0)return C[n][k];
    if(n==k||k==0)return 1;
    else return C[n][k]=comb(n-1,k,C,n1,k1)+comb(n-1,k-1,C,n1,k1);
}