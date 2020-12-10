#include<iostream>
#include<algorithm>
int n,m;
int x[100000]={},y[100000]={};
bool check(int time){
    for(int  i=0,j=0;i<n;){
        while(j<m && y[j]<x[i]-time)j++;
        if(j==m||y[j]>x[i]+time)return false;
        i++;
        j++;
    }
    return true;
}
int main(){
    std::cin>>n>>m;
    for(int i=0;i<n;i++)std::cin>>x[i];
    for(int j=0;j<m;j++)std::cin>>y[j];
    std::sort(x,x+n);
    std::sort(y,y+m);
    int l=0,r=10000000000;
    while(l<r){
        int m=(l+r)/2;
        if(check(m))r=m;
        else l=m+1;
    }
    std::cout<<l<<std::endl;
}