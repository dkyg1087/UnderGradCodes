#include<iostream>
using namespace std;
int main(){
    int a[10001]={},P,C,counter,i,k=1,j,tar;
    char cmd;
    for(counter=1;;counter++){
        while(cin>>P>>C){
            if(P==0&&C==0)break;
            cout<<"Case "<<counter<<":"<<endl;
            for(i=1;i<=P;i++){
                a[i]=i;
            }
            for(j=C;j>0;j--){
                cin>>cmd;
                if(cmd=='N'){
                    cout<<a[1]<<endl;
                    a[P+1]=a[1];
                    for(i=0;i<P+1;i++){
                        a[i]=a[i+1];
                    }
                }
                else{
                    cin>>tar;
                    for(k=1;a[k]!=tar;k++);
                    a[0]=a[k];
                    for(i=k;(i-1)>=0;i--){
                        a[i]=a[i-1];
                    }
                }
            }
        }
        if(P==0&&C==0)break;
    }
    return 0;
}