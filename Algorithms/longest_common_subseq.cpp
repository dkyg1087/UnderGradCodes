#include<iostream>
using namespace std;
int arr[20005][20005]={};
int main(){
    string str1,str2;
    cin>>str1>>str2;
    for(int i=1;i<str1.length()+1;i++){
        for(int j=1;j<str2.length()+1;j++){
            if(str1[i-1]==str2[j-1])arr[i][j]=arr[i-1][j-1]+1;
            else arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
        }
    }
    cout<<arr[str1.length()][str2.length()]<<endl;
    return 0;
}