#include<iostream>
using namespace std;
int main(){
    int num,depth,amount;
    cin>>num;
    while(num--){
        int targ_num=1;
        cin>>depth>>amount;
        for(int i=1;i<depth;i++){
            if(amount%2==1){
                targ_num*=2;
                amount=(amount+1)/2;
            }
            else{
                targ_num=targ_num*2+1;
                amount/=2;
            }
        }
        cout<<targ_num<<endl;
    }
}