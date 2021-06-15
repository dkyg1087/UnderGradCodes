#include<iostream>

using namespace std;
class Item{
    public:
        int name,weight,value;
}items[8001];
int used[8001][8001]={},c[8001][8001];
int main(){
    int size = 0,count = 0;
    cin>>size;
    int name=0,weight=0,value=0;
    while(cin>>name>>weight>>value){
        if(name==-1)break;
        items[count].name=name;
        items[count].weight=weight;
        items[count].value=value;
        count++;
    }

    for(int i=0;i<count;i++){
        for(int j=0;j<size+1;j++){
            if(j-items[i].weight<0){
                c[i+1][j]=c[i][j];
            }
            else{
                c[i+1][j]=max(c[i][j-items[i].weight]+items[i].value,c[i][j]);
                if(c[i][j-items[i].weight]+items[i].value>c[i][j]){
                    used[i][j]=1;
                }
            }
        }
    }
    for(int i = count-1,j = size;i>=0;i--){
        if(used[i][j]==1){
            cout<<items[i].name<<" ";
            j-=items[i].weight;
        }
    }
    cout<<endl<<c[count][size]<<endl;
}