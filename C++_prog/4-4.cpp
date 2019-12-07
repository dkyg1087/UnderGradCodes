#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int A[5000]={},B[5000]={},i=0,j=0,max_A,max_B,ans=0;
bool cmp(int x,int y){
    return x>y;
}
void findA(int);
void findB(int); 
int main(){
    int x;
    cin>>x;
    for(;x>0;x--){
        i=j=ans=0;
        for(int z=0;z<5000;z++){
            A[z]=B[z]=0;
        }
        int count,num;
        cin>>count;
        for(;count>0;count--){
            cin>>num;
            if(num>0){
                A[i]=num;
                i++;
            }
            else{
                B[j]=-num;
                j++;
            }
        }
        max_A=i;
        max_B=i;
        sort(A,A+max_A,cmp);
        sort(B,B+max_B,cmp);
        if(A[0]>B[0]){
            ans++;
            findB(A[0]);
        }
        else{
            ans++;
            findA(B[0]);
        }
        cout<<++ans<<endl;
    }
}
void findA(int x){
    i++;
    int flag=0;
    for(;i<max_A;i++){
        if(A[i]<x){
            flag=1;
            break;
        }
    }
    if(flag==1){
        ans++;
        findB(A[i]);
    }
    else return;
}
void findB(int x){
    j++;
    int flag=0;
    for(;j<max_B;j++){
        if(B[j]<x){
            flag=1;
            break;
        }
    }
    if(flag==1){
        ans++;
        findB(A[j]);
    }
    else return;
}