#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[100][100];
int main(){
    int _max=0,i,j;
    for(i=0;i<100;i++)for(j=0;j<100;j++)arr[i][j]=999;
    while(cin>>i>>j){
        _max=max(i,max(j,_max));
        cin>>arr[i][j];
    }
    for(i=0;i<=_max;i++)arr[i][i]=0;
    int **aarr=new int*[_max+1];
    for(i=0;i<=_max;i++)aarr[i]=new int[_max+1];
    for(i=0;i<=_max;i++)for(j=0;j<=_max;j++)aarr[i][j]=999;
    for(i=0;i<=_max;i++)aarr[i][0]=0;
    for(i=0;i<_max;i++)for(j=0;j<=_max;j++)for(int k=0;k<=_max;k++)aarr[i+1][k]=min(aarr[i+1][k],aarr[i][j]+arr[j][k]);
    for(int x=1;x<=_max;x++){
        cout<<aarr[x][0];
        for(int z=1;z<=_max;z++){
            if(aarr[x][z]>100)cout<<" "<<"i";
            else cout<<" "<<aarr[x][z];
        }
        cout<<endl;
    }
}