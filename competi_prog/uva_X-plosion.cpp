#include<iostream>
using namespace std;
int x,y;
int parent[100001]={};
int its_Parent(int x){
    if(x==parent[x])return x;
    return parent[x]=its_Parent(parent[x]);
}
int main(){
    while(cin>>x>>y){
        int ignored=0;
        for(int i=0;i<100001;i++)parent[i]=i;
        parent[x]=y;
        while(cin>>x,x!=-1){
            cin>>y;
            x=its_Parent(x);
            y=its_Parent(y);
            if(x==y)ignored++;
            else parent[x]=y;
        }
        cout<<ignored<<endl;
    }
}