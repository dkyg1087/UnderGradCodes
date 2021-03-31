#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int num,max,pay;
    while(cin>>num>>max>>pay){
        if(num==0&&max==0&&pay==0)break;
        int morning[10001]={},evening[10001]={},sum=0;
        for(int i=0;i<num;i++)cin>>morning[i];
        for(int i=0;i<num;i++)cin>>evening[i];
        sort(morning,morning+num);
        sort(evening,evening+num,cmp);
        for(int i=0;i<num;i++){
            if(morning[i]+evening[i]>max){
                sum+=((morning[i]+evening[i]-max)*pay);
            }
        }
        cout<<sum<<endl;
    }
}