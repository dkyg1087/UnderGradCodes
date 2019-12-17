#include<iostream>
#include<vector>
using namespace std;
void check(vector<int> &heap,int i){
    if(heap[i]<heap[i/2]){
        int temp=heap[i/2];
        heap[i/2]=heap[i];
        heap[i]=temp;
        check(heap,i/2);
    }
    else return;
}
int main(){
    vector<int>heap;
    heap.push_back(0);
    int num;
    while(cin>>num){
        heap.push_back(num);
        check(heap,heap.size()-1);
        cout<<"["<<1<<"]"<<heap[1];
        for(int i=2;i<heap.size();i++){
            cout<<" "<<"["<<i<<"]"<<heap[i];
        }
        cout<<endl;
    }
}