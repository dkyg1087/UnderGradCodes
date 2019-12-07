#include<iostream>
using namespace std;
typedef struct Tree *tpt;
struct Tree {
         int data;
         tpt leftChild=NULL, rightChild=NULL;
};
void get_in(int data,tpt &treepointer){
    if(treepointer==NULL){
        treepointer=new Tree;
        treepointer->data=data;
    }
    else{
        if(treepointer->data>data)get_in(data,treepointer->leftChild);
        else get_in(data,treepointer->rightChild);
    }
    return;
}
int find(tpt treept,int level){
    if(treept==NULL)return -1;
    int left=find(treept->leftChild,++level);
    int right=find(treept->rightChild,level);
    return right>left?right>level?right:level:left>level?left:level;
}
int main(){
    tpt head=NULL;
    int data;
    while(cin>>data){
        get_in(data,head);
        if(head==NULL)cout<<"NULL";
    }
    cout<<find(head,1)-1<<endl;

}