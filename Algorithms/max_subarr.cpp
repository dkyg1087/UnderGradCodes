#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;
int arr[50001]={};
int findMaxCrossing(int,int,int);
int findMaxSubArr(int,int);
int main(){
    int num=0;
    while(cin>>arr[num]){
        num++;
    }
    cout<<findMaxSubArr(0,num-1)<<endl;
};
int findMaxSubArr(int low,int high){
    if(low == high)return arr[low];
    else {
        int mid = (high+low)/2,leftMax=0,rightMax=0,crossMax=0;
        leftMax = findMaxSubArr(low,mid);
        rightMax = findMaxSubArr(mid+1,high);
        crossMax = findMaxCrossing(low,mid,high);
        return max(max(leftMax,rightMax),crossMax);
    }
}
int findMaxCrossing(int low,int mid,int high){
    int leftSum=INT_MIN,sum=0,rightSum=INT_MIN;
    for(int i=mid;i>=low;i--){
        sum+=arr[i];
        leftSum=max(leftSum,sum);
    }
    sum=0;
    for(int i=mid+1;i<=high;i++){
        sum+=arr[i];
        rightSum=max(rightSum,sum); 
    }
    return leftSum+rightSum;
}