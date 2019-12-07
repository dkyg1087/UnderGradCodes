#include<iostream>
#define size top+1//將size直觀化
using namespace std;
class StackArray{
    private:
        int top;
        int capacity;
        int *stack;
        void DoubleCapacity();
    public:
        StackArray():top(-1),capacity(1){
            stack=new int[capacity];
        }
    void Push(int x);
    void Pop();
    bool IsEmpty();
    int Top();
    int getSize();
};
void StackArray::DoubleCapacity(){
    capacity*=2;
    int *newstack=new int[capacity];
    for(int i=0;i<capacity/2;i++){
        newstack[i]=stack[i];
    }
    delete[] stack;
    stack=newstack;
}
bool StackArray::IsEmpty(){
    if(top==-1)return true;//如果是空的top是-1
    else return false;
}
int StackArray::Top(){
    if(IsEmpty()){
        return -1;//如果是空的top是-1
    }
    else return stack[top];//不然return最上面的數字
}
int StackArray::getSize(){
    return size;
}
void StackArray::Pop(){
    stack[top]=0;//將要pop的值歸0
    top--;
    if(IsEmpty())cout<<"Stack is empty."<<endl<<endl;//確認是否為空的
}
void StackArray::Push(int x){
    if(size==capacity)DoubleCapacity();//如果滿了空間翻倍
    stack[top+1]=x;
    top++;
}
int main(){
    StackArray Stack;//靜態
    if(Stack.IsEmpty())cout<<"Stack is empty."<<endl<<endl;
    Stack.Push(14);
    cout<<"top: "<<Stack.Top()<<endl<<"size: "<<Stack.getSize()<<endl<<endl;
    Stack.Push(9);
    cout<<"top: "<<Stack.Top()<<endl<<"size: "<<Stack.getSize()<<endl<<endl;
    Stack.Push(7);
    cout<<"top: "<<Stack.Top()<<endl<<"size: "<<Stack.getSize()<<endl<<endl;
    Stack.Pop();
    cout<<"top: "<<Stack.Top()<<endl<<"size: "<<Stack.getSize()<<endl<<endl;
    Stack.Pop();
    cout<<"top: "<<Stack.Top()<<endl<<"size: "<<Stack.getSize()<<endl<<endl;
    Stack.Pop();
    cout<<"top: "<<Stack.Top()<<endl<<"size: "<<Stack.getSize()<<endl<<endl;
    return 0;
}