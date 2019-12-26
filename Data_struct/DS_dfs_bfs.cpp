#include<iostream>
#include<vector>
using namespace std;
int arr[1024][1024];
bool A[100];
int find_next(int i,int j,int maxx){
    for(int k=j+1;k<=maxx;k++){
        if(arr[i][k]==1){
            return k;
        }
    }
    return -1;
}
void dfs(int num,int maxx){
    int temp=-1;
    A[num]=true;
    if(num!=0)cout<<" "<<num;
    else{
        cout<<num;
    }
    for(;;){
        temp=find_next(num,temp,maxx);
        if(temp==-1)return;
        if(!A[temp])dfs(temp,maxx);
    }
}
void bfs(int num,int maxx){
    vector<int>vec;
    int temp=-1;
    A[num]=true;
    for(;;){
        
    }
}
int main(){
    for(int i=0;i<100;i++)A[i]=false;
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
    cout<<"Depth First Search:"<<endl;
    dfs(0,maxx);
    cout<<endl<<endl<<"Breadth First Search:"<<endl;
    for(int i=0;i<100;i++)A[i]=false;
    cout<<endl;
}