#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n,temp1,temp2,arr[50001]={},q=-10000;
    cin>>n;
    while(cin>>temp1>>temp2){
        if(temp1==0&&temp2==0)break;
        else arr[temp1]=temp2;
    }
    int ans[n+1]={};
    ans[0]=0;
    for(int j=1;j<=n;j++){
        q=-1000;
        for(int i=1;i<=j;i++){
            q=max(q,arr[i]+ans[j-i]);
        }
        ans[j]=q;
    }
    cout<<ans[n]<<endl;
    return 0;
}