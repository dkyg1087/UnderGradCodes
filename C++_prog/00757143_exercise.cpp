#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string str;
int count=1,couple,i;
void check(void);
int main(void){
    int x;
    int* test;
    test=(int*)malloc(10^7);
    cin>>x;
    for(;x>0;x--){
       cin>>str;
       for(i=0;i<=str.length();i++){
           if(str[i]=='.'){
           str.erase(i);
           }
        }
        check();
        cout<<couple;
    }
    free(test);
    return 0;
}
void check(void){
    for(i=0;i<str.length();i++){
        if(str[i]=='p'&&str[i+1]=='q'){
            str.erase(i,i+1);
            couple++;
            count++;
        }
    }
    if(count>0){
        count=0;
        check();
    }
    else return;
}