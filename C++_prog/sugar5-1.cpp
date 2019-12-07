#include <iostream>  
#include <string>  
using namespace std;  
struct node{  
    string data;  
    struct node *next;  
};  
/*ADD function*/  
void add(node **headptr , node *term){  
    if(*headptr==NULL){  
        *headptr=term;  
    }  
    else{  
        node *temp=*headptr;  
        while(temp->next!=NULL)  
            temp=temp->next;  
        temp->next=term;  
    }  
    term->next=NULL;  
}  
/*INSERT function*/  
void insert(node **headptr , string i , string ai){  
    node *current=*headptr , *before=NULL;  
    while(current->data!=ai){  
            before=current;  
            current=current->next;  
    }  
    node *temp = new node;  
    before->next=temp;  
    temp->data=i;  
    temp->next=current;  
}  
/*REMOVE function*/  
void remove(node **headptr , string r){  
    node *before;  
    if((*headptr)->data==r){  //head=r   
        (*headptr)=(*headptr)->next;  //head point head->next  
    }  
    else{  
        node *current=*headptr;  //current start from head  
        while(current->data!=r){  
            before=current;  
            current=current->next;  
        }  
        before->next=current->next;  
    }  
}  
/*SHOW function*/  
void show(node *n){  
    cout<<n->data;  
    n=n->next;  
    while(n!=NULL){  
        cout<<" "<<n->data;  
        n=n->next;  
    }  
    cout<<endl;  
}  
/*main*/  
int main(){  
    node *head=NULL,*term;  
    string order,r,i,ai;  //order,remove,insert,after insert  
    while(cin>>order){  
        if(order=="ADD"){  
            term=new node;  
            cin>>term->data;  
            add(&head,term);  
        }  
        else if(order=="INSERT"){  
            cin>>i>>ai;  
            insert(&head,i,ai);  
        }  
        else if(order=="REMOVE"){  
            cin>>r;  
            remove(&head,r);  
        }  
        else if(order=="SHOW")  
            show(head);  
    }  
   return 0;  
}