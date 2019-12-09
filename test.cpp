#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int globalvar=23;
int main(){
    int localvar;
    cin>>localvar;
    vector<string>str_vec;
    str_vec.push_back("str");
    cout<<globalvar<<" "<<localvar<<" "<<str_vec[0]<<endl;
}