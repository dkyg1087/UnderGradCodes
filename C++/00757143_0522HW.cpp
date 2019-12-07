#include<iostream>
#include<assert.h>
using namespace std;
class Queue{
    private:
        enum {SIZE=10};
        int data[SIZE];
        int first_index;//I assume this is where the first number will be.
        int element_no;//I assume this is the number of elements it has stored.
    public:
        void push(int a);
        void pop();
        void print();//I add this so I can print out easily.
        int top();
        int size();
        Queue():element_no(0),first_index(-1){};
};
int Queue::top(){
    return 0;//I have no idea what this fuction should do,you didn't specify.  
}
int Queue::size(){
    return 0;//I have no idea what this fuction should do,you didn't specify.
}
void Queue::push(int a){
    cout<<"> push "<<a<<endl;
    assert(element_no+1<=SIZE);//if it is full already,shut down the program.
    for(int i=first_index;i>=0;i--){
        data[i+1]=data[i];//copy the element to the next one.
    }
    data[0]=a;
    first_index++;
    element_no++;
    print();
    return;
}
void Queue::pop(){
    cout<<"> pop"<<endl;
    first_index--;
    element_no--;
    print();
    return;
}
void Queue::print(){
    for(int i=0;i<10;i++)cout<<"+-----";
    cout<<"+"<<endl;
    int k=element_no;
    for(int i=0;i<10;i++){
        if(k>0){
            cout<<"|   "<<data[i]<<" ";
            k--;
        }
        else cout<<"|     ";
    }
    cout<<"|"<<endl;
    for(int i=0;i<10;i++)cout<<"+-----";
    cout<<"+"<<endl;
}
int main(){
    Queue Q;
    Q.push(0);
    Q.push(2);
    Q.push(4);
    Q.push(6);
    Q.push(8);
    Q.pop();
    Q.pop();
    Q.pop();
    return 0;
}