#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef struct Tree *tpt;
struct Tree {
    string data;
    tpt leftChild=NULL, rightChild=NULL;
};
void replace(char targ,char num,string &str){
    for(int i=0;i<str.size();i++)if(str[i]==targ)str[i]=num;
}
int apart1(string str){
    int count=0;
    int k=1;
    do{
        if(str[k]=='('){
            count++;
        }
        else if(str[k]==')'){
            count--;
        }
        k++;
    }while(count>0);  
    return k;
}
void construct(tpt &treept,string str){
    //cout<<str<<endl;
    treept=new Tree;
    if(str[0]!='('){
        treept->data=str;
        return;
    }
    else{
        str.erase(str.begin());
        str.erase(str.end()-1);
        treept->data=str[0];
        int n=apart1(str);
        string str1=str.substr(1,n-1);
        string str2=str.substr(n,str.size()-n);
        construct(treept->leftChild,str1);
        construct(treept->rightChild,str2);
    }
}
void calculate(tpt &treept){
    if(treept==NULL||isdigit(treept->data[0])){
        return;
    }
    if(isdigit(treept->leftChild->data[0])&&isdigit(treept->rightChild->data[0])){
        
        int ans;
        switch(treept->data[0]){
            case '*':
                ans=stoi(treept->leftChild->data)*stoi(treept->rightChild->data);
                //cout<<ans<<endl;
                break;
            case '/':
                ans=stoi(treept->leftChild->data)/stoi(treept->rightChild->data);
                //cout<<ans<<endl;
                break;
            case '+':
                ans=stoi(treept->leftChild->data)+stoi(treept->rightChild->data);
                //cout<<ans<<endl;
                break;
            case '-':
                ans=stoi(treept->leftChild->data)-stoi(treept->rightChild->data);
                //cout<<ans<<endl;
                break;
            default:
                break;
        }
        treept->data=to_string(ans);
        treept->leftChild=treept->rightChild=NULL;
    }
    else{
        calculate(treept->leftChild);
        calculate(treept->rightChild);
    }
    return;
}
int main(){
    tpt head=NULL;
    string str;
    getline(cin,str);
    for(int i=0;i<str.size();){
        if(str[i]==' ')str.erase(str.begin()+i);
        else i++;
    }
    char var,junk,num;
    while(cin>>var>>junk>>num)replace(var,num,str);
    construct(head,str);
    while(!isdigit(head->data[0]))calculate(head);
    cout<<head->data<<endl;
}
