#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
typedef struct Tree *tpt;
struct Tree {
    string data;
    tpt leftChild=NULL, rightChild=NULL;
};
int find_level(tpt treept,int level){
    if(treept==NULL)return -1;
    int left=find_level(treept->leftChild,++level);
    int right=find_level(treept->rightChild,level);
    return right>left?right>level?right:level:left>level?left:level;
}
int balance(tpt head){
    int left=find_level(head->leftChild,1)-1;
    int right=find_level(head->rightChild,1)-1;
    return abs(left-right);
}
void preorder(tpt treept){
    if(treept){
        cout<<treept->data<<" ";
        preorder(treept->leftChild);
        preorder(treept->rightChild);
    }
    return;
};
void inorder(tpt treept){
    if(treept){
        inorder(treept->leftChild);
        cout<<treept->data<<" ";
        inorder(treept->rightChild);
    }
    return;
}
void postorder(tpt treept){
    if(treept){
        
        postorder(treept->leftChild);
        postorder(treept->rightChild);
        cout<<treept->data<<" ";
    }
    return;
}
tpt find(tpt treept,string targ){
    if(treept==NULL)return NULL;
    if(treept->data==targ)return treept;
    else{
        tpt result=find(treept->leftChild,targ);
        return result?result:find(treept->rightChild,targ);
    }
}
void construct(tpt &treept,vector<string> vecc){
    if(treept==NULL){
        treept=new Tree;
        treept->data=vecc[0];
        treept->leftChild=new Tree;
        treept->leftChild->data=vecc[1];
        if(vecc.size()>2){
            treept->rightChild=new Tree;
            treept->rightChild->data=vecc[2];
        }
    }
    else{
        tpt temp=find(treept,vecc[0]);
        temp->leftChild=new Tree;
        temp->leftChild->data=vecc[1];
        if(vecc.size()>2){
            temp->rightChild=new Tree;
            temp->rightChild->data=vecc[2];
        }
    }
    return;
}
int main(){
    string str;
    tpt head=NULL;
    while(getline(cin,str),str!="0"){
        vector<string>vec;
        int i,j;
        for(i=j=0;i<str.size();i++){
            if(str[i]==' '){
                vec.push_back(str.substr(j,i-j));
                j=i+1;
            }
            else if(i==str.size()-1){
                vec.push_back(str.substr(j,i-j+1));
            }
        }
        construct(head,vec);
    }
    cout<<"Preorder: ";
    preorder(head);
    cout<<endl;
    cout<<"Inorder: ";
    inorder(head);
    cout<<endl;
    cout<<"Postorder: ";
    postorder(head);
    cout<<endl;
    cout<<"The balance factor is "<<balance(head)<<endl;
}
