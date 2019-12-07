#include<iostream>
#include<string>
#include<string.h>
using namespace std;
string ans;
bool mirror(string str,int i,int j){
    if(j<=i)return true;
    else if(str[i]==str[j])return mirror(str,i+1,j-1);
    else return false;
}
void check(string str,int i,int j){
    if(ans.length()>(j-i+1))return;
    else if(mirror(str,i,j)){
        ans=str.substr(i,j-i+1);
        return;
    }
    return;
}
int main(){
    string str;
    int i,j;
    cin>>str;
    for(i=0;i<str.size();i++){
        for(j=i+1;j<str.size();j++){
            if(str[i]==str[j])check(str,i,j);
        }
    }
    cout<<ans<<endl;
}