#include<iostream>
using namespace std;
int arr[50001]={};
void merge(int *arr,int left,int middle,int right){
    int L_amount,R_amount;
    L_amount=middle-left+1;
    R_amount=right-middle;
    int Left_arr[L_amount];
    int Right_arr[R_amount];
    for(int i=0;i<L_amount;i++)Left_arr[i]=arr[left+i];
    for(int i=0;i<R_amount;i++)Right_arr[i]=arr[middle+1+i];
    int i=0,j=0,k=left;
    while(i<L_amount&&j<R_amount){
        if(Left_arr[i]<=Right_arr[j])arr[k++]=Left_arr[i++];
        else arr[k++]=Right_arr[j++];
    }
    while(i<L_amount)arr[k++]=Left_arr[i++];
    while(j<R_amount)arr[k++]=Right_arr[j++];
}
void MergeSort(int *arr,int left,int right){
    if(left<right){
        int middle=left+(right-left)/2;
        MergeSort(arr,left,middle);
        MergeSort(arr,middle+1,right);
        merge(arr,left,middle,right);
    }
}
int main(){
    int num,i=-1;
    while(cin>>num)arr[++i]=num;
    MergeSort(arr,0,i);
    for(int j=0;j<=i;j++){
        cout<<arr[j]<<" ";
    }
    cout<<endl;
}