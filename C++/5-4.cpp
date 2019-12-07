#include<iostream>
using namespace std;
int main(){
    int arr[2][52],i;
    char b;
    cin>>i;
    for(;i>0;i--)cin>>b>>arr[0][b-'A']>>arr[1][b-'A'];
    cin.get();
    for(;;){
        int flag=0,ans=0,j=1;
        char alph[100]={};
        for(i=0;;){
            cin.get(b);
            if(b=='(')flag++;
            else if(isalpha(b)){
                alph[i]=b;
                i++;
            }
            else if(b=='\n')break;
            else if(b==')'){
                if(arr[1][alph[i-2]-'A']!=arr[0][alph[i-1]-'A']){
                    cout<<"error"<<endl;
                    flag=1;
                    break;
                }
                else{
                    ans+=(arr[0][alph[i-2]-'A']*arr[1][alph[i-2]-'A']*arr[1][alph[i-1]-'A']);
                    arr[0][25+j]=arr[0][alph[i-2]-'A'];
                    arr[1][25+j]=arr[1][alph[i-1]-'A'];
                    j++;
                    alph[i-1]=0;
                    alph[i-2]=25+j+'A';
                    i--;
                    flag--;
                }
            }
        }
        if(flag==0){
            cout<<ans<<endl;
        }
    }
    return 0;
}