#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    double x,y;
    int amount;
    cin>>amount;
    for(;amount>0;amount--){
        double ans;
        cin>>x>>y;
        ans=pow(pow(x-10,2)+pow(y-10,2),0.5);
        if(ans<=1)cout<<"10"<<endl;
        else if(ans<=2)cout<<"9"<<endl;
        else if(ans<=3)cout<<"8"<<endl;
        else if(ans<=4)cout<<"7"<<endl;
        else if(ans<=5)cout<<"6"<<endl;
        else if(ans<=6)cout<<"5"<<endl;
        else if(ans<=7)cout<<"4"<<endl;
        else if(ans<=8)cout<<"3"<<endl;
        else if(ans<=9)cout<<"2"<<endl;
        else if(ans<=10)cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }
}