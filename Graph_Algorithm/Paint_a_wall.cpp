#include<iostream>
using namespace std;

int parent[1000000]={};
int ssize[1000000]={};
int find_parent(int x){
    if(x==parent[x])return x;
    else return parent[x]=find_parent(parent[x]);
}

bool make_set(int x,int y){
    int left=find_parent(x);
    int right=find_parent(y);
    if(left==right)return false;
    if(ssize[left]<=ssize[right]){
        parent[left]=right;
        ssize[right]+=ssize[left];
    }
    else{
        parent[right]=left;
        ssize[left]+=ssize[right];
    }
    return true;
}
int main(){
    int cost=0,count,left=0,right=0;
    cin>>count;
    int leftt[count+1]={},rightt[count+1]={};
    for(int i=1;i<=count;i++)cin>>leftt[i];
    for(int j=1;j<=count;j++)cin>>rightt[j];
    for(int i=0;i<=count;i++){
        parent[i]=i;
        ssize[i]=1;
    }
    int i=1;
    while(count--){
        if(make_set(leftt[i],rightt[i])){
            cost++;
        }
        i++;
    }
    cout<<cost<<endl;
}