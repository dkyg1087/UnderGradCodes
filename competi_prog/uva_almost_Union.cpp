#include<iostream>
using namespace std;
int parent[20001];
int iden[20001];
int its_Parent(int x){
    if(x==parent[x])return x;
    return parent[x]=its_Parent(parent[x]);
}
void move(int x,int y,int people){
    if (its_Parent(x)==its_Parent(y))return;
    for(int j=1;j<people+1;j++){
        if(j==its_Parent(x))continue;
        if(its_Parent(j)==its_Parent(x)){
            parent[j]=its_Parent(x);
            iden[j]=1;
        }
    }
    iden[its_Parent(x)]--;
    parent[x]=its_Parent(y);
    iden[x]=1;
    iden[its_Parent(y)]++;
    return;
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
    int people,num;
    cin>>people>>num;
    if(num<=0)return 0;
    for(int i=1;i<=people;i++){
        parent[i]=i;
        iden[i]=1;
    }
    while(num--){
        int cmd,targ,targ2;
        cin>>cmd>>targ;
        switch(cmd){
            case 1:
                cin>>targ2;
                set(targ,targ2);
                break;
            case 2:
                cin>>targ2;
                move(targ,targ2,people);
                break;
            case 3:{
                int sum=0;
                for(int i=1;i<people+1;i++){
                    if(its_Parent(i)==its_Parent(targ))sum+=i;
                }
                cout<<iden[its_Parent(targ)]<<" "<<sum<<endl;
                break;
            }
        }
    }
}
/*
        0 1 2 3 4 5
iden      1 2 1 1 1
parent    2 2 4 5 5


5 7
1 1 2
2 3 4
1 3 5
3 4
2 4 1
3 4
3 3


*/