#include<iostream>
#include<algorithm>
using namespace std;
int _head[100000]={},_knight[100000]={};
int main(){
    int head,knight;
    while(cin>>head>>knight,head!=0){
        int cost=0;
        for(int i=0;i<head;i++)cin>>_head[i];
        for(int j=0;j<knight;j++)cin>>_knight[j];
        if(head>knight){
            cout<<"Loowater is doomed!"<<endl;
            continue;
        }
        sort(_head,_head+head);
        sort(_knight,_knight+knight);
        int i,j;
        for(i=0,j=0;i<knight;i++){
            if(_knight[i]>=_head[j]){
                cost+=_knight[i];
                if(++j==head)break;
            }
        }
        if(j==head)cout<<cost<<endl;
        else cout<<"Loowater is doomed!"<<endl;
    }
}