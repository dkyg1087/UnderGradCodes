#include<iostream>
#include<string>
using namespace std;
int main(){
    string a[10000],cmd,term,comp;
    int i=0,k,check=0,j;
    for(k=0;k<10000;k++){
        a[k]="nothing";
    }
    while(cin>>cmd){
        if(cmd=="ADD"){
            cin>>a[i];
            i++;
        }
        else if(cmd=="REMOVE"){
            cin>>term;
            for(k=0;a[k]!=term;k++);
            for(j=k;a[j]!="nothing";j++){
                a[j]=a[j+1];
            }
            i--;
        }
        else if(cmd=="SHOW"){
            for(k=0;k<i;k++){
                if(a[k]!="nothing"){
                    cout<<a[k];
                    break;
                }
            }
            for(k=k+1;k<i;k++){
                if(a[k]!="nothing"){
                    cout<<" "<<a[k];
                }
            }
            cout<<endl;
        }
        else{
            cin>>term>>comp;
            for(k=0;a[k]!=comp;k++);
            for(j=i-1;j>=k;j--){
                a[j+1]=a[j];
            }
            a[k]=term;
            i++;
        }
    }
    return 0;
}