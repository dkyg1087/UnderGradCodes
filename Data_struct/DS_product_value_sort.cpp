#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct List* lspt;
struct List{
    string name;
    vector<int>value;
    lspt link=NULL;
};
lspt is_in(string targ,lspt head){
    if(head==NULL)return NULL;
    else{
        for(lspt temp=head;temp;temp=temp->link){
            if(temp->name==targ){
                return temp;
            }
        }
        return NULL;
    }
}
bool cmp(int x,int y){
    return x<y;
}
int main(){
    int num;
    cin>>num;
    lspt head=NULL;
    string name;
    int value,flag=0;
    while(num--){
        cin>>name>>value;
        lspt ptr=is_in(name,head);
        if(head==NULL){
            head=new List;
            head->name=name;
            head->value.push_back(value);
        }
        else if(ptr){
            ptr->value.push_back(value);
        }
        else{
            lspt temp;
            for(temp=head;temp->link;temp=temp->link);
            temp->link=new List;
            temp->link->name=name;
            temp->link->value.push_back(value);
        }
    }
    for(lspt temp=head;temp;temp=temp->link){
        cout<<temp->name<<",";
        sort(temp->value.begin(),temp->value.end(),cmp);
        for(int i=0;i<temp->value.size();i++){
            cout<<temp->value[i]<<",";
        }
        cout<<endl;
    }
}