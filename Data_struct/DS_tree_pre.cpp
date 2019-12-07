#include<iostream>
#include<vector>
using namespace std;
int main(void){
    int num,x,y,z,i=1;
    cin>>num>>x>>y>>z;
    vector<int>tree;
    tree.push_back(0);
    tree.push_back(x);
    tree.push_back(y);
    tree.push_back(z);
    while(cin>>x,x!=-1){
        cin>>y>>z;
        for(int j=0;j<tree.size();j++)if(tree[j]==x)i=j;
        while(tree.size()<i*2)tree.push_back(0);
        tree.push_back(y);
        tree.push_back(z);
    }
    cout<<tree[1];
    for(int i=2;i<tree.size();i++){
        cout<<" "<<tree[i];
        if(tree[i]==num)break;
    }
    cout<<endl;
    return 0;
}