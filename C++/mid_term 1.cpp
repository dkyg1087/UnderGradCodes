#include<iostream>
using namespace std;
int main(){
    for(;;){
        long X,current,last,max=0;
        int count,flag=0;
        cin>>X;
        if(X==0)break;
        current=last=X;
        for(count=1;count<100000;count++){
            if(last%2==0){
                current=last/2;
            }
            else{
                current=(3*last)+1;
            }
            last=current;
            if(current>max)max=current;
            if(current==1){
                flag=1;
                break;
            }
        }
        if(flag==0){
            max=0;
            count=0;
        }
        cout<<X<<" "<<count<<" "<<max<<endl;
    }
    return 0;
}