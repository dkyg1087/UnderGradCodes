#include <iostream>
using namespace std;
int main(){
    int num,start,end,end_now;
    cin>>num>>start>>end;
    end_now=end;
    cout<<1<<" ";
    while(cin>>num>>start>>end){
        if(end_now<=start){
            cout<<num<<" ";
            end_now=end;
        }
    }
    cout<<endl;
    return 0;
}