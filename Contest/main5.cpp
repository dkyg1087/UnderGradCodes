#include<iostream>
#include<string>
#include<stdio.h>
#include<climits>
#include<cmath>
using namespace std;
int main(){
    char a[64],b[64],temp;
    int count;
    cin>>count;
    getchar();
    string temp2,zero="0";
    for(;count>0;count--){
        int i=0;
            getline(cin,temp2);
            temp2.append(zero);
            //if(cin.eof())break;
            for(int z=0;z<temp2.length();z++){
                temp=temp2[z];
                if(isalpha(temp))a[i++]=temp;
                else if(isdigit(temp)){
                    temp-='0';
                    for(int k=z+1;k<temp2.length();k++){
                        if(isdigit(temp2[k]))temp+=temp2[k]*pow(10,k-z);
                        else break;
                    }
                    temp%=26;
                    for(int j=0;j<i;j++){
                        if(a[j]+temp>90){
                            a[j]=a[j]+temp-26;
                        }
                        else a[j]+=temp;
                        cout<<a[j];
                    }
                i=0;
                }
            }
        if(count!=1)cout<<endl;
    }
}