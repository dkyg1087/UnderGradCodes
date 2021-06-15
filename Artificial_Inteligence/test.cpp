#include<iostream>
using namespace std;

int main(){
    string b="+++++++++XX++OOOX+++OXOO++X+XX++++++";
    string a = b;
    a[0]='6';
    cout<<a<<" "<<b<<b.length()<<endl;
}