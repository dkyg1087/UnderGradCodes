#include<iostream>
#include<string.h>
using namespace std;
int main(){
    string str;
    while(cin>>str){
        int ST,flag=0;
        for(ST=1;ST<10000;ST++){
            int arr[51]={},temp,i,k,it=0;
            for(i=0;i<str.length();i++){
                temp=str[i]+ST-'A';
                if((temp/10000)>0){
                    for(k=4;k>=0;k--){
                        arr[it+k]=temp%10;
                        temp/=10;
                    }
                    it+=5;
                }
                else if((temp/1000)>0){
                    for(k=3;k>=0;k--){
                        arr[it+k]=temp%10;
                        temp/=10;
                    }
                    it+=4;
                }
                else if((temp/100)>0){
                    for(k=2;k>=0;k--){
                        arr[it+k]=temp%10;
                        temp/=10;
                    }
                    it+=3;
                }
                else if((temp/10)>0){
                    for(k=1;k>=0;k--){
                        arr[it+k]=temp%10;
                        temp/=10;
                    }
                    it+=2;
                }
                else{
                    arr[it]=temp;
                    it++;
                }
            }
            for(it=it-1;it>2;it--){
                for(int i=it;i>0;i--){
                    arr[i]=(arr[i]+arr[i-1])%10;
                }
                for(int i=0;i<=it;i++){
                    arr[i]=arr[i+1];
                }
            }
            if(arr[0]==1&&arr[1]==0&&arr[2]==0){
                flag=1;
                cout<<ST<<endl;
                break;
            }
        }//10000
        if(flag==0){
            cout<<":("<<endl;
        }
        else{
            flag=0;
        }
    }
    return 0;
}