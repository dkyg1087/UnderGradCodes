#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;
int arr[50001]={};
int main(){
    int num,i=0,l_max=0,g_max=INT_MIN;
    while(cin>>num)arr[i++]=num;
    for(int j=0;j<i;j++){
        l_max=max(arr[j],arr[j]+l_max);
        g_max=max(g_max,l_max);
    }
    cout<<g_max<<endl;
}