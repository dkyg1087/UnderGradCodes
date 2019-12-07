#include<iostream>
#define N 20002
using namespace std;
int people;
int parent[N];
int iden[N];
int its_Parent(int x){
    if(x==parent[x])return x;
    return parent[x]=its_Parent(parent[x]);
}
int get_enemy(int x){
    return x+people;
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
bool are_friends(int x,int y){
    return its_Parent(x)==its_Parent(y);
}
bool are_enemies(int x,int y){
    return its_Parent(get_enemy(x))==its_Parent(y)||its_Parent(x)==its_Parent(get_enemy(y));
}
bool set_friends(int x,int y){
    int x_e=its_Parent(get_enemy(x));
    int y_e=its_Parent(get_enemy(y));
    x=its_Parent(x);
    y=its_Parent(y);
    if(x_e==y||y_e==x)return false;
    set(x,y);
    set(x_e,y_e);
    return true;
}
bool set_enemies(int x,int y){
    int x_e=its_Parent(get_enemy(x));
    int y_e=its_Parent(get_enemy(y));
    x=its_Parent(x);
    y=its_Parent(y);
    if(x==y)return false;
    set(y,x_e);
    set(x,y_e);
    return true;

}
int main(){
    cin>>people;
    for(int i=0;i<=people*2;i++){
        parent[i]=i;
        iden[i]=1;
    }
    int cmd,x,y;
    while(cin>>cmd>>x>>y,cmd!=0){
        if(cmd==1){
            if(!set_friends(x,y)){
                cout<<"-1"<<endl;
            }
        }
        else if(cmd==2){
            if(!set_enemies(x,y)){
                cout<<"-1"<<endl;
            }
        }
        else if(cmd==3){
            if(are_friends(x,y))cout<<"1"<<endl;
            else cout<<"0"<<endl;
        }
        else if(cmd==4){
            if(are_enemies(x,y))cout<<"1"<<endl;
            else cout<<"0"<<endl;
        }
        else break;
    }
    return 0;
}