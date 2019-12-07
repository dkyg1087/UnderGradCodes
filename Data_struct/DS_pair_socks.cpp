#include<iostream>
#include<vector>
using namespace std;
int main(){
    int num,num2,temp;
    cin>>num;
    num2=num;
    vector<int>data_num;
    while(num2--){
        cin>>temp;
        data_num.push_back(temp);
    }
    for(int count=0;count<data_num.size();count++){
        temp=data_num[count];
        string str;
        vector<string>socks;
        while(temp--){
            cin>>str;
            int flag=0;
            for(int i=0;i<socks.size();i++){
                if(str==socks[i]){
                    socks.erase(socks.begin()+i);
                    flag=1;
                    break;
                }
            }
            if(flag==0)socks.push_back(str);
        }
        cout<<socks.size()<<endl;
    }
}