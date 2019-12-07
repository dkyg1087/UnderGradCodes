#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    long double a,ans=0;
    long long unsigned int num,cash,ans2=0;
    cin>>a>>num>>cash;
    if(num==1){
        cout<<cash*(1+a);
        return 0;
    }
    if(num==0){
        cout<<cash;
        return 0;
    }
    for(;num>0;num--){
        ans+=cash;
        ans*=(1+a);
    }
    cout<<fixed<<setprecision(0)<<ans<<endl;
}