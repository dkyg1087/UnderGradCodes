#include<iostream>
using namespace std;
class Lists{
    public:
        int x;
        Lists* ptr=NULL;
};
int main(){
    Lists* ptr1=new Lists;
    ptr1->x=30;
    Lists* ptr2=new Lists;
    ptr2->x=40;
    ptr1->ptr=ptr2;
    delete(ptr2);
    if(ptr1->ptr==NULL)cout<<"NULL"<<endl;
    else cout<<"Not NULL";
    if(ptr2==NULL)cout<<"NULL"<<endl;
    else cout<<"Not NULL";
    cout<<ptr2->x;
}