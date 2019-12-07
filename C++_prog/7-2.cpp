#include<iostream>
#include<math.h>
using namespace std;
void set(int dist,int st);
int arr[20][20]={},height,width,sta_x,sta_y,goal_x,goal_y;
int main(){
    int dis[20],step,i,j;
    cin>>height>>width>>sta_x>>sta_y>>goal_x>>goal_y>>step;
    for(i=0;i<step;i++)cin>>dis[i];
    arr[sta_x][sta_y]=1;
    for(i=0;i<step;i++){
        set(dis[i],i);
    }
    if(arr[goal_x][goal_y]==pow(2,step))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
void set(int dist,int st){
    int i,j;
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            if(arr[i][j]==pow(2,st)){
                int a;
                if(i-(dist%height)<0)a=i-dist%height+height;
                else a=i-dist%height;
                arr[a][j]=pow(2,st+1);
                if(i+(dist%height)>height)a=i+dist%height-height;
                else a=i+dist%height;
                arr[a][j]=pow(2,st+1);
                if(j-(dist%width)<0)a=j-dist%width+width;
                else a=j-dist%width;
                arr[i][a]=pow(2,st+1);
                if(j+(dist%width)>width)a=j+dist%width-width;
                else a=j+dist%width;
                arr[i][a]=pow(2,st+1);
                
            }
        }
    }
    return;
}