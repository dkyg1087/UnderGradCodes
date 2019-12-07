#include<iostream>
#include<ctype.h>
using namespace std;
int main(){
    int i,count;
    char a;
    cin>>count;
    getchar();
    for(;count>0;count--){
        int max=0,alph[26]={};
        for(;;){
          a=getchar();
          if(isalpha(a)){
              if(isupper(a))alph[a-'A']++;
              else alph[a-'a']++;
          }
          else if(a=='\n')break;
        }
        for(i=0;i<26;i++){
            if(alph[i]>max){
                max=alph[i];
            }
        }
        for(i=0;i<26;i++){
            if(alph[i]==max){
                a=i+'a';
                cout<<a;
            }
        }
        cout<<" "<<max<<endl;
    }
}