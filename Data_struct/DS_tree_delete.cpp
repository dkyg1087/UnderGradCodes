#include<iostream>
#include<vector>
#include<utility>
#include<sstream>
using namespace std;
typedef struct Tree *tpt;
struct Tree {
    int data;
    tpt leftChild=NULL, rightChild=NULL;
};
pair<tpt,tpt> find(tpt treept,int targ,tpt parent){
    if(treept==NULL)return make_pair(treept,parent);
    if(treept->data==targ)return make_pair(treept,parent);
    else{
        pair<tpt,tpt>result=find(treept->leftChild,targ,treept);
        return result.first?result:find(treept->rightChild,targ,treept);
    }
}
tpt travel(tpt treept){
	if(!treept->rightChild)return treept;
	else travel(treept->rightChild);
}
void _delete(tpt &treept,int targ){
	pair<tpt,tpt>family=find(treept,targ,NULL);
	if(!family.first){
		cout<<"no "<<targ<<endl;
		return;
	}
	else{
		char pos=(!family.second)?'H':family.second->leftChild==family.first?'L':'R';
		if(!family.first->leftChild&&!family.first->rightChild){
			if(pos=='H'){
				delete(treept);
				treept=NULL;
			}
			else if(pos=='L'){
				delete(family.second->leftChild);
				family.second->leftChild=NULL;
			}
			else{
				delete(family.second->rightChild);
				family.second->rightChild=NULL;
			}
		}
		else if(family.first->leftChild&&!family.first->rightChild){
			if(pos=='H'){
				treept=family.first->leftChild;
				delete(family.first);
			}
			else if(pos=='L'){
				family.second->leftChild=family.first->leftChild;
				delete(family.first);
			}
			else{	
				family.second->rightChild=family.first->leftChild;
				delete(family.first);
			}
		}
		else if(!family.first->leftChild&&family.first->rightChild){
			if(pos=='H'){
				treept=family.first->rightChild;
				delete(family.first);
			}
			else if(pos=='L'){
				family.second->leftChild=family.first->rightChild;
				delete(family.first);
			}
			else{	
				family.second->rightChild=family.first->rightChild;
				delete(family.first);
			}
		}
		else{
			tpt target=travel(family.first->leftChild);
			int num=target->data;
			_delete(treept,target->data);
			family.first->data=num;
		}
	} 
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
	stringstream ss(str);
	while(ss>>str)vec.push_back(stoi(str));
	for(int i=0;i<vec.size();i++)insert(head,vec[i]);
	cout<<"Binary search tree (before):"<<endl;
	preorder(head);
	cout<<endl;
	getline(cin,str);
	//str.erase(str.size()-1,1);
	vector<int>vecc;
	ss=stringstream(str);
	while(ss>>str)vecc.push_back(stoi(str));
	for(int i=0;i<vecc.size();i++)_delete(head,vecc[i]);
	cout<<"Binary search tree (after):"<<endl;
	preorder(head);
	cout<<endl;
}