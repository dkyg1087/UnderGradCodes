#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
bool cmp(int x,int y){
    return abs(x)>abs(y);
}
int main(){
    int p,i,j;
    while(cin>>p){
        for(i=0;i<p;i++){
            for(i=0;i<p;i++){
                int x,A[5000]={},ans=0,temp;
                cin>>x;
                for(j=0;j<x;j++)cin>>A[j];
                sort(A,A+x,cmp);
                for(j=0;j<x;j++){
                    if(A[j]!=0){
                        if(j==0){
                            temp=0;
                            ans++;
                        }
                        else if(A[temp]/A[j]<0){
                            temp=j;
                            ans++;
                        }
                    }
                }
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}