#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
bool cmp(int x,int y){
    return abs(x)<abs(y);
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[2*n]={},x[m]={};
    for(int i=0;i<n; i++)scanf("%d",&a[i]);
    for(int j=n;j<2*n; j++){
        scanf("%d",&a[j]);
        a[j]*=-1;
    }
    int maxAmount=0;
    for(int k=0;k<m; k++){
        scanf("%d",&x[k]);
        maxAmount=max(maxAmount,x[k]);
    }
    sort(a,a+(2*n),cmp);
    long long int ansArr[maxAmount+1]={};
    int currentVal=0,i=0;
    long long int currentInterval=0;
    for(int k=0;k<maxAmount+1;k++){
        if(k==abs(a[i])){
            if(a[i]>=0){
                ansArr[k]=currentInterval;
                ansArr[k]+=currentVal;
                currentInterval+=currentVal;
                currentVal++;
                i++;
            }
            else{
                ansArr[k]=currentInterval;
                ansArr[k]+=currentVal;
                currentInterval+=currentVal;
                currentVal--;
                i++;
            }
        }
        else if(k>abs(a[i])){
            if(a[i]>=0){
                currentVal++;
            }
            else{
                currentVal--;
            }
            k--;
            i++;
        }
        else{
            ansArr[k]=currentInterval;
            ansArr[k]+=currentVal;
            currentInterval+=currentVal;
        }
    }
    //cout<<ansArr[x[0]];
    printf("%lld",ansArr[x[0]]);
    for(int i=1;i<m;i++){
        //cout<<" "<<ansArr[x[i]];
        printf(" %lld",ansArr[x[i]]);
    }
    printf("\n");
}