#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int value[500001]={};
    value[0]=0;
    int i=0;
    while(cin>>i>>value[i]);
    //for(int j=0;j<=i;j++)cout<<value[j]<<" ";
    int r[500001]={};
    r[0]=0;
    for(int i=1;i<=n;i++){
        int q=-1000;
        for(int j=1;j<=i;j++){
            q=max(q,value[j]+r[i-j]);
        }
        r[i]=q;
    }
    cout<<r[n]<<endl;
}