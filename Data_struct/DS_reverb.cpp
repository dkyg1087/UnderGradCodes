#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
int main(){
    int bot,top,flag=0;
    cin>>bot>>top;
    for(int i=bot+1;i<top;i++){
        string str,str_r;
        str=to_string(i);
        str_r=str;
        reverse(str_r.begin(),str_r.end());
        if(!(str.compare(str_r))){
            flag=1;
            cout<<str<<" ";
        }
    }
    if(flag==0){
            cout<<0<<endl;
        }
        else cout<<endl;
}