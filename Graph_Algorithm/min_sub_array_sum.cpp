#include<iostream>
#include<algorithm>

int main(){
    int length,target;
    std::cin>>length>>target;
    int arr[length]={};
    for(int i=0; i<length; i++)std::cin>>arr[i];
    std::make_heap(arr,arr+length);
    int ans=0;
    while(target>0){
        if(length==0){
            ans=0;
            break;
        }
        target-=arr[0];
        std::cout<<arr[0]<<" ";
        ans++;
        std::pop_heap(arr,arr+length);
        length--;
    }
    std::cout<<ans<<std::endl;
}