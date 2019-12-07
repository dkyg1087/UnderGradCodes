#include<iostream>
using namespace std;
int main(){
    string str;
    while(getline(cin,str),str!="0"){
        for(int i=0;str.size();i++){
            cout<<str[i];
        }
        cout<<endl;
    }
}