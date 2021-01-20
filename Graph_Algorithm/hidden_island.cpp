#include<iostream>
using namespace std;
int familySize[100000000]={};
void mark(int x,int y,int targetNum,int intoNum,int map[][1002]){
    if(map[x-1][y]==targetNum){
        map[x-1][y]=intoNum;
        familySize[intoNum]++;
        mark(x-1,y,targetNum,intoNum,map);
    }
    if(map[x+1][y]==targetNum){
        map[x+1][y]=intoNum;
        familySize[intoNum]++;
        mark(x+1,y,targetNum,intoNum,map);
    }
    if(map[x][y-1]==targetNum){
        map[x][y-1]=intoNum;
        familySize[intoNum]++;
        mark(x,y-1,targetNum,intoNum,map);
    }
    if(map[x][y+1]==targetNum){
        map[x][y+1]=intoNum;
        familySize[intoNum]++;
        mark(x,y+1,targetNum,intoNum,map);
    }
    return;
}
int main(){
    int count,i,j,familyName=1,islandCount=0;
    int map[1002][1002]={};
    cin>>count;
    while(count--){
        cin>>i>>j;
        if(map[i][j]!=0)continue;
        
    }
}   