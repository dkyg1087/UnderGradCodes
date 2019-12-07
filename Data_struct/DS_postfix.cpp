#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
void postfix(){
    char x;
    int i=-1;
    cin>>x;
    vector<char>Sign;
    for(;;){
        if(x=='(')postfix();
        else if(isalpha(x)||isdigit(x)){
            cout<<x<<" ";
        }
        else if(x=='+'||x=='-'||x=='*'||x=='/'){
            i++;
            Sign.push_back(x);
            if(Sign.size()>1){
                if(Sign[i-1]=='*'||Sign[i-1]=='/'||x=='+'||x=='-'){
                    cout<<Sign[i-1]<<" ";
                    Sign.erase(Sign.begin()+i-1);
                    i--;
                }
            }
        }
        else if(x==')'){
            while(Sign.size()>0){
                cout<<Sign[i]<<" ";
                Sign.erase(Sign.begin()+i);
                i--;
            }
            return;
        }
        else if(x=='\n'){
            Print:
            while(Sign.size()>1){
                cout<<Sign[i]<<" ";
                Sign.erase(Sign.begin()+i);
                i--;
            }
            cout<<Sign[0]<<endl;
            return;
        }
        else{
            x=getchar();
            continue;
        }
        if((x=getchar())==EOF)goto Print;
    }
}
int main(){
    int amount;
    char junk;
    cin>>amount;
    while(amount--)postfix();
    return 0;
}