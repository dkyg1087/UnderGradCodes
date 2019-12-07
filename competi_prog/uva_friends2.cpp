#include<iostream>
int parent[30001];
int iden[30001];
int its_Parent(int x){
    if(iden[x]==1)return x;
    else return parent[x];
}
bool are_Friend(int x,int y){
    if(its_Parent(x)==its_Parent(y))return true;
    else return false;
}
void set_Friend(int x,int y,int people){
    if(iden[x]==-1&&iden[y]==-1){
        iden[x]=1;
        iden[y]=0;
        parent[x]++;
        parent[y]=x;
    }
    else if(iden[x]==-1||iden[y]==-1){
        if(iden[x]==-1){
            int temp=x;
            x=y;
            y=temp;
        }
        iden[y]=0;
        parent[y]=its_Parent(x);
        parent[its_Parent(x)]++;
    }
    else{
        if(are_Friend(x,y))return;
        else{
            parent[its_Parent(y)]=its_Parent(x);
            parent[its_Parent(x)]++;
            iden[y]=0;
            for(int i=1;i<people+1;i++){
                if(parent[i]==its_Parent(y)&&iden[i]==0){
                    parent[i]=its_Parent(x);
                    parent[its_Parent(x)]++;
                }
            }
        }
    }
}
int main(){
    int count;
    std::cin>>count;
    if(count<=0)return 0;
    while (count--){
        int people,pairs;
        std::cin>>people>>pairs;
        for(int i=0;i<people+1;i++){
            iden[i]=-1;
            parent[i]=0;
        }
        if(pairs==0){
            std::cout<<1<<std::endl;
            continue;
        }
        int x,y;
        while(pairs--){
            std::cin>>x>>y;
            set_Friend(x,y,people);
        }
        int max=0;
        for(int j=0;j<people+1;j++){
            if(iden[j]==1&&parent[j]>max){
                max=parent[j];
            }
        }
        std::cout<<max+1<<std::endl;
    }
    return 0;
}