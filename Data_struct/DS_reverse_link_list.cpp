#include<iostream>
using namespace std;
typedef struct List* lspt;
struct List{
    int data;
    lspt link=NULL;
};
lspt invert(lspt lead){
    lspt middle,trail;
    middle=NULL;
    while(lead){
        trail=middle;
        middle=lead;
        lead=lead->link;
        middle->link=trail;
    }
    return middle;
}
int main(){
    lspt head=NULL;
    int data;
    while(cin>>data){
        if(head==NULL){
            head=new List;
            head->data=data;
        }
        else{
            lspt temp=head;
            while(temp->link!=NULL){
                temp=temp->link;
            }
            temp->link = new List;
            temp->link->data=data;
        }
    }
    head=invert(head);
    cout<<head->data;
    for(lspt temp=head->link;temp;temp=temp->link){
        cout<<" "<<temp->data;
    }
    cout<<endl;
}