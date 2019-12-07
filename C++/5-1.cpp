#include<iostream>
#include<string>
#include<string.h>
using namespace std;
struct words{
    string str;
    words *next;
};
int main(){
    string cmd,comp;
    words* head;
    while(cin>>cmd){
        char a=cmd[0];
        switch (a)
        {
        case 'A':
        {
            if(head==NULL){
                head=(words*)malloc(sizeof(words));
                cin>>head->str;
                head->next=NULL;
            }
            else{
                words* temp=head,*term=(words*)malloc(sizeof(words));
                cin>>term->str;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=term;
                term->next=NULL;
            }
            break;
        }
        case 'I':
        {
            words* temp=head,*before,*term=(words*)malloc(sizeof(words));
            cin>>term->str>>comp;
            while(temp->str!=comp){
                before=temp;
                temp=temp->next;   
            }
            before->next=term;
            term->next=temp;
            break;
        }
        case 'R':
        {
            words* temp=head,*before;
            cin>>comp;
            if(head->str==comp){
                head=head->next;
                break;
            }
            while(temp->str!=comp){
                before=temp;
                temp=temp->next;
            }
            before->next=temp->next;
            free(temp);
            break;
        }
        case 'S':
        {
            words* temp=head;
            cout<<temp->str;
            temp=temp->next;
            while(temp->next!=NULL){
                cout<<" "<<temp->str;
                temp=temp->next;
            }
            cout<<endl;
            break;
        }
        default:
        {
            cout<<"I don't know this shit!"<<endl;
            break;
        }
        }
    }
    return 0;
}