#include<iostream>
#include<vector>
using namespace std;
void buble(vector<int> &heap,int i){
    if(heap.size()-1>=2*i+1){
        if(heap[2*i]<heap[2*i+1]){
            if(heap[2*i]<heap[i]){
                int temp=heap[2*i];
                heap[2*i]=heap[i];
                heap[i]=temp;
                buble(heap,2*i);
            }
            else{
                if(heap[2*i+1]<heap[i]){
                    int temp=heap[2*i+1];
                    heap[2*i+1]=heap[i];
                    heap[i]=temp;
                    buble(heap,2*i+1);
                }
                else return;
            }
        }
        else{
            if(heap[2*i+1]<heap[i]){
                int temp=heap[2*i+1];
                heap[2*i+1]=heap[i];
                heap[i]=temp;
                buble(heap,2*i+1);
            }
            else{
                if(heap[2*i]<heap[i]){
                int temp=heap[2*i];
                heap[2*i]=heap[i];
                heap[i]=temp;
                buble(heap,2*i);
                }
                else return;
            }
        }
    }
    else{
        if(heap.size()-1>=2*i){
            if(heap[2*i]<heap[i]){
                int temp=heap[2*i];
                heap[2*i]=heap[i];
                heap[i]=temp;
                buble(heap,2*i);
            }
        }
        else return;
    }
}
void check(vector<int> &heap,int i){
    if(heap[i]<heap[i/2]){
        int temp=heap[i/2];
        heap[i/2]=heap[i];
        heap[i]=temp;
        check(heap,i/2);
    }
    else return;
}
void print(vector<int> heap){
    cout<<"["<<1<<"]"<<heap[1];
    for(int i=2;i<heap.size();i++){
        cout<<" "<<"["<<i<<"]"<<heap[i];
    }
    cout<<endl;
}
int main(){
    vector<int>heap;
    heap.push_back(0);
    int num;
    while(cin>>num){
        heap.push_back(num);
        check(heap,heap.size()-1);
    }
    print(heap);
    while(heap.size()!=2){
        heap[1]=heap[heap.size()-1];
        heap.erase(heap.end()-1);
        buble(heap,1);
        print(heap);
    }
}