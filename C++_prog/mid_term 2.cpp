#include<iostream>
using namespace std;
int main(){
    int c=0,N,goal;
    while(cin>>N>>goal){
        c++;
        int a[N+1]={},i,k,j,z,flag=0,count=0,temp=0;
        for(i=0;i<20;i++){
            count=0;
            cin>>k;
            for(j=1;j<N+1&&flag==0;j++){
                if(a[j]==0)count++;
                if(count==k){
                    a[j]++;
                    count=0;
                }
                for(z=1;z<N+1;z++)if(a[z]==0)temp++;
                if(temp==goal){
                    flag=1;
                    break;
                }
                else{
                    temp=0;
                }
            }
        }
        cout<<"Selection #"<<c<<endl;
        for(i=1;i<N+1;i++){
            if(a[i]==0){
                cout<<i;
                break;
            }
        }
        for(i=i+1;i<N+1;i++){
            if(a[i]==0){
                cout<<" "<<i;
            }
        }
        cout<<endl<<endl;
    }
    return 0;
}