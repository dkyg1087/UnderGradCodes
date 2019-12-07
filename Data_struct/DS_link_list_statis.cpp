#include<iostream>
#include<string>
#include<string.h>
using namespace std;
typedef struct List* lspt;
struct List{
    string data;
    int counter=1;
    lspt link=NULL;
};
lspt is_in(string targ,lspt head){
    if(head==NULL)return NULL;
    string str1="";
    for(int i=0;i<targ.length();i++){
        str1.append(to_string(tolower(targ[i])));
    }
    for(lspt temp=head;temp;temp=temp->link){
        string str2="";
        for(int i=0;i<temp->data.length();i++){
            str2.append(to_string(tolower(temp->data[i])));
        }
        if(str1==str2)return temp;
    }
    return NULL;
}
int main(){
    int len=0;
    lspt head=NULL;
    string str;
    while(cin>>str,str!="#Exit"){
        if(str[0]=='#'){
            if(str[1]=='P'){
                for(lspt temp=head;temp;temp=temp->link)cout<<temp->data<<", "<<temp->counter<<endl;
            }
            else if(str[1]=='I'){
                int num;
                cin>>num>>str;
                if(num<len){
                    lspt ptr=is_in(str,head);
                    if(ptr){
                        ptr->counter+=1;
                    }
                    else{
                        lspt temp=new List;
                        lspt last,now=head;
                        for(int i=0;i<num;i++){
                            last=now;
                            now=now->link;
                        }
                        last->link=temp;
                        temp->data=str;
                        temp->link=now;
                        len++;
                    }
                }
            }
            else if(str[1]=='A'){
                cin>>str;
                lspt ptr=is_in(str,head);
                if(ptr){
                    ptr->counter+=1;
                }
                else{
                    lspt temp;
                    for(temp=head;temp->link;temp=temp->link);
                    temp->link=new List;
                    temp->link->data=str;
                    len++;
                }
            }
        }
        else{
            lspt ptr=is_in(str,head);
            if(ptr){
                ptr->counter+=1;
            }
            else{
                if(head==NULL){
                    head=new List;
                    head->data=str;
                    len++;
                }
                else{
                    lspt temp;
                    for(temp=head;temp->link;temp=temp->link);
                    temp->link=new List;
                    temp->link->data=str;
                    len++;
                }
            }
        }
    }
}
