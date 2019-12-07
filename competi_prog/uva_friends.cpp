#include<iostream>
using namespace std;
int parent[30001];
int iden[30001];
int its_Parent(int x){
    if(x==parent[x])return x;
    return parent[x]=its_Parent(parent[x]);
}
void set(int x,int y){
    x=its_Parent(x);
    y=its_Parent(y);
    if(x==y)
        return;
    if(iden[x]<=iden[y]){
        parent[x]=y;
        iden[y]+=iden[x];
    }
    else{
        parent[y]=x;
        iden[x]+=iden[y];
    }
}
int main(){
    int people,pairs,count;
    cin>>count;
    while(count--){
        cin>>people>>pairs;
        for(int i=1;i<=people;i++){
        parent[i]=i;
        iden[i]=1;
        }
        for(int i=1;i<=pairs;i++){
            int a,b;
            cin>>a>>b;
            set(a,b);
        }
        int ans=0;
        for(int i=1;i<=people;i++){
            ans=max(ans,iden[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}