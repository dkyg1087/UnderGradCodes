#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool not_done(bool *visited,int size) {
    for(int i=0;i<size;i++)if(visited[i]==false)return true;
    return false;
}
int main(){
    int start;
    cin>>start;
    vector<vector<int>>vec;
    int _max=0,num;
    while(cin>>num){
        if(num>_max)_max=num;
        vector<int>temp;
        temp.push_back(num);
        cin>>num;
        if(num>_max)_max=num;
        temp.push_back(num);
        cin>>num;
        temp.push_back(num);
        vec.push_back(temp);
    }
    bool *done=new bool(_max+1);
    int *arr=new int(_max+1);
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
        for(int i=0;i<vec.size();i++){
            if(vec[i][0]==min_num){
                arr[vec[i][1]]=min(arr[vec[i][1]],arr[min_num]+vec[i][2]);
            }
        }
    }
    for(int i=0;i<=_max;i++)cout<<i<<": "<<arr[i]<<endl;
}