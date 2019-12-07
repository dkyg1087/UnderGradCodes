#include<iostream>
using namespace std;
int main(){
    int count,error,a[2][52]={},i=0,ans,j=0,flag;
    char b;
    cin>>count;
    for(;count>0;count--){
        cin>>b;
        cin>>a[0][b-'A']>>a[1][b-'A'];
    }
    cin.get();
    while(cin.get(b)){
        ans=flag=i=error=0;
        int alph[100]={};
        for(;;){
            if(b=='\n'){
                break;
            }
            else if(isalpha(b)){
                alph[i]=b;
                i++;
            }
            else if(b==')'){
                if(a[0][alph[i-1]-'A']!=a[1][alph[i-2]-'A']){
                    cout<<"error"<<endl;
                    i=0;
                    error=1;
                    break;
                }
                else{
                    a[0][25+j]=a[0][alph[i-2]-'A'];
                    a[1][25+j]=a[1][alph[i-1]-'A'];
                    ans+=a[0][alph[i-2]-'A']*a[1][alph[i-2]-'A']*a[1][alph[i-1]-'A'];
                    alph[i-2]='Z'+j;
                    i=i-1;
                    j++;
                    flag--;
                }
            }
            else flag++;
            cin.get(b);
        }
        if(flag==0&&error==0){
            cout<<ans<<endl;
        }      
    }
    return 0;
}