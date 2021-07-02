#include<iostream>
using namespace std;
void test(int A[],bool visited[],int result[],int start){
    cout<<"HERE"<<endl;
    visited[start] = true;
    result[start]=A[start];
    if(result[4]!=0){
        for(int i =0 ;i<5;i++){
            cout<<result[i]<<" ";
        }
        cout<<endl;
    } 
    for(int i=0;i<5;i++){
        if(visited[i]==false){
            test(A,visited,result,i);
        }
    }
}
int main(){
    int A[5]={1,2,3,4,5};
    bool visited[5]={false,false,false,false,false};
    int result[5] = {};
    int start = 1;
    test(A,visited,result,start);
}