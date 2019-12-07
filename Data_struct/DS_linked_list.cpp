#include<iostream>
using namespace std;
typedef struct List* lspt;
struct List{
    int data;
    lspt link=NULL;
};
void print(lspt);
int main(){
    int amount;
    cin>>amount;
    int flag=0; 
    while(amount--){
        if(flag!=0)cout<<endl;
        char cmd;
        int length=0;
        lspt head=NULL;
        while(cin>>cmd){
            if(cmd=='f'){
                int data;
                cin>>data;
                if(head==NULL){
                    head=new List;
                    head->data=data;
                    print(head);
                    length++;
                }
                else{
                    lspt temp=new List;
                    temp->data=data;
                    temp->link=head;
                    head=temp;
                    print(head);
                    length++;
                }
            }
            else if(cmd=='a'){
                int data;
                cin>>data;
                if(head==NULL){
                    head=new List;
                    head->data=data;
                    print(head);
                    length++;
                }
                else{
                    lspt temp=head;
                    while(temp->link!=NULL){
                        temp=temp->link;
                    }
                    temp->link = new List;
                    temp->link->data=data;
                    print(head);
                    length++;
                }
            }
            else if(cmd=='i'){
                int position,data;
                cin>>data>>position;
                if(position<=0){
                    if(head==NULL){
                        head=new List;
                        head->data=data;
                        print(head);
                        length++;
                    }
                    else{
                        lspt temp=new List;
                        temp->data=data;
                        temp->link=head;
                        head=temp;
                        print(head);
                        length++;
                    }
                }
                else if(position>=length){
                    if(head==NULL){
                        head=new List;
                        head->data=data;
                        print(head);
                        length++;
                    }
                    else{
                        lspt temp=head;
                        while(temp->link!=NULL){
                            temp=temp->link;
                        }
                        temp->link = new List;
                        temp->link->data=data;
                        print(head);
                        length++;
                    }
                }
                else{
                    lspt temp=new List;
                    lspt last,now=head;
                    for(int i=0;i<position;i++){
                        last=now;
                        now=now->link;
                    }
                    last->link=temp;
                    temp->data=data;
                    temp->link=now;
                    print(head);
                }
            }
            else break;
        }
        flag++;
    }
}
void print(lspt pt){
    cout<<"Created Linked list is:";
    lspt temp=pt;
    for(;temp;temp=temp->link){
        cout<<"  "<<temp->data;
    }
    cout<<" "<<endl;
}