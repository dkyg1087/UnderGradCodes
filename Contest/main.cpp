#include<iostream>
using namespace std;
int main(){
    int x;
    cin>>x;
    for(;x>0;x--){
        int num;
        cin>>num;
        int sum=0;
        for(;num>0;num--){
            sum+=num;
        }
        cout<<sum<<endl;
    }
    return 0;
}