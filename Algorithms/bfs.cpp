#include<iostream>
#include<queue>
#include<utility>
#include <iomanip>

using namespace std;

int main(){
    int mazeHeight,mazeWidth,startPointX,startPointY,endPointX,endPointY;
    char dummy;
    cin>>mazeHeight>>mazeWidth>>startPointX>>startPointY>>endPointX>>endPointY;
    endPointX-=1;
    endPointY-=1;
    int mazeArr[mazeHeight][mazeWidth];
    for(int i=0;i<mazeHeight;i++){
        for(int j=0;j<mazeWidth;j++){
            cin>>dummy;
            if(dummy == '0')mazeArr[i][j]=-2;
            else mazeArr[i][j]=-1;
        }
    }
    queue<pair<pair<int,int>,int>> Queue;
    Queue.push(make_pair(make_pair(startPointX-1,startPointY-1),0));
    while(!Queue.empty()){
        pair<pair<int,int>,int> a = Queue.front();
        Queue.pop();
        mazeArr[a.first.first][a.first.second]=a.second;
        if(a.first.first==endPointX&&a.first.second==endPointY)break;
        if(a.first.first>=1)if(mazeArr[a.first.first-1][a.first.second]==-2)Queue.push(make_pair(make_pair(a.first.first-1,a.first.second),a.second+1));//top
        if(a.first.second<mazeWidth-1){
            if(a.first.first>=1)if(mazeArr[a.first.first-1][a.first.second+1]==-2)Queue.push(make_pair(make_pair(a.first.first-1,a.first.second+1),a.second+1));//top right
            if(mazeArr[a.first.first][a.first.second+1]==-2)Queue.push(make_pair(make_pair(a.first.first,a.first.second+1),a.second+1));//right
        }
        if(a.first.first<mazeHeight-1){
            if(a.first.second<mazeWidth-1)if(mazeArr[a.first.first+1][a.first.second+1]==-2)Queue.push(make_pair(make_pair(a.first.first+1,a.first.second+1),a.second+1));//bottom right
            if(mazeArr[a.first.first+1][a.first.second]==-2)Queue.push(make_pair(make_pair(a.first.first+1,a.first.second),a.second+1));//bottom
            if(a.first.second>=1)if(mazeArr[a.first.first+1][a.first.second-1]==-2)Queue.push(make_pair(make_pair(a.first.first+1,a.first.second-1),a.second+1));//bottom left
        }
        if(a.first.second>=1){
            if(mazeArr[a.first.first][a.first.second-1]==-2)Queue.push(make_pair(make_pair(a.first.first,a.first.second-1),a.second+1));//left
            if(a.first.first>=1)if(mazeArr[a.first.first-1][a.first.second-1]==-2)Queue.push(make_pair(make_pair(a.first.first-1,a.first.second-1),a.second+1));//top left
        }
    }
    // for(int i=0;i<mazeHeight;i++){
    //     for(int j=0;j<mazeWidth;j++){
    //         cout<<setw(5)<<mazeArr[i][j];
    //     }
    //     cout<<endl;
    // }
    
}