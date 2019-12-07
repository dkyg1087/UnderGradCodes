#include<iostream>
#include<vector>
#include <utility>
using namespace std;
typedef struct Tree *tpt;
struct Tree {
    int data;
    tpt leftChild=NULL, rightChild=NULL;
};
pair<tpt,tpt> find(tpt treept,int targ){
    if(treept==NULL)return NULL;
    if(treept->data==targ)return treept;
    else{
        tpt result=find(treept->leftChild,targ);
        return result?result:find(treept->rightChild,targ);
    }
}
void delete(tpt &treept,int targ){
	pair<tpt,tpt>pairs;
}
void insert(tpt &treept,int num){
	if(treept==NULL){
		treept=new Tree;
		treept->data=num;
	}
	else{
		if(treept->data>num)insert(treept->leftChild,num);
		else insert(treept->rightChild,num);
	}
}
void preorder(tpt treept){
    if(treept){
        cout<<treept->data<<" ";
        preorder(treept->leftChild);
        preorder(treept->rightChild);
    }
    return;
};
int main(){
	tpt head=NULL;
	string str;
	getline(cin,str);
	str.erase(str.size()-1,1);
	int i,j;
	vector<int>vec;
	for(i=j=0;i<str.size();i++){
		if(str[i]==' '){
			vec.push_back(stoi(str.substr(j,i-j)));
			j=i+1;
		}
		else if(i==str.size()-1){
                vec.push_back(stoi(str.substr(j,i-j+1)));
            }
	}
	for(int i=0;i<vec.size();i++)insert(head,vec[i]);
	cout<<"Binary search tree (before):";
	preorder(head);
	cout<<endl;
	getline(cin,str);
	str.erase(str.size()-1,1);
	vector<int>vecc;
	for(i=j=0;i<str.size();i++){
		if(str[i]==' '){
			vecc.push_back(stoi(str.substr(j,i-j)));
			j=i+1;
		}
		else if(i==str.size()-1){
                vecc.push_back(stoi(str.substr(j,i-j+1)));
            }
	}
	for(int i=0;i<vecc.size();i++)delete(head,vecc[i],pairs);
	cout<<"Binary search tree (after):";
	preorder(head);
	cout<<endl;
}