#include<iostream>
using namespace std;
typedef struct List* lspt;
struct List{
    int data;
    lspt link=NULL;
};
int main(){
    int num,start,amount;
    cin>>num>>start>>amount;
    lspt head=new List;
    head->data=1;
    head->link=NULL;
    for(int i=2;i<=num;i++){
        lspt temp=head;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link = new List;
        temp->link->data=i;
    }
    lspt temp=head;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=head;
    int length=num;
    temp=head;
    for(int i=1;i<start;i++){
        temp=temp->link;
    }
    int count=1,flag=0;
    lspt last;
    while(length>0){
        for(count=1;count<amount;count++){
            last=temp;
            temp=temp->link;
        }
        if(flag==0){
            cout<<temp->data;
            flag++;
        }
        else cout<<" "<<temp->data;
        last->link=temp->link;
        free(temp);
        temp=last->link;
        length--;
    }
    cout<<endl;
}