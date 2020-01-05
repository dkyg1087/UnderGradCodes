#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool not_done(bool *visited,int size) {
    for(int i=0;i<size;i++)if(visited[i]==false)return true;
    return false;
}
int main(){
    int start=0;
    int _max=0,num,border;
    cin>>border;
    _max=border-1;
    int aarr[100][100];
    vector<vector<int>>vec;
    for(int i=0;i<border;i++){
        for(int j=0;j<border;j++){
            cin>>aarr[i][j];
            if(aarr[i][j]==1){
                vector<int>temp;
                temp.push_back(i);
                temp.push_back(j);
                temp.push_back(1);
                vec.push_back(temp);
            }
        }
    }
    int real_max=0;
    bool *done=new bool(_max+1);
    int *arr=new int(_max+1);
    for(num=0;num<border;num++){
        start=num;
        for(int i=0;i<=_max;i++){
            if(i==start)arr[i]=0;
            else arr[i]=99999;
            done[i]=false;
        }
        while(not_done(done,_max+1)){
            int minn=999,min_num;
            for(int i=0;i<=_max;i++){
                if(arr[i]<minn&&!done[i]){
                    minn=arr[i];
                    min_num=i;
                }
            }
            done[min_num]=true;
            for(int i=0;i<vec.size();i++)if(vec[i][0]==min_num)arr[vec[i][1]]=min(arr[vec[i][1]],arr[min_num]+vec[i][2]);
        }
        sort(arr,arr+border);
        real_max=max(real_max,arr[border-1]);
    }
    cout<<real_max<<endl;
}