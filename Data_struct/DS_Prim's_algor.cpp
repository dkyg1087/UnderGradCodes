#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool not_done(bool *visited,int size) {
    for(int i=0;i<size;i++){
        if(visited[i]==false){
            return true;
        }
    }
    return false;
}
int main(){
    vector<vector<int>>vec;
    int stpt,_max=0,num;
    cin>>stpt;
    while(cin>>num){
        if(num>_max)_max=num;
        vector<int>temp;
        temp.push_back(num);
        cin>>num;
        temp.push_back(num);
        if(num>_max)_max=num;
        cin>>num;
        temp.push_back(num);
        vec.push_back(temp);
    }
    vector<int>candi;
    candi.push_back(stpt);
    bool* visited=new bool(_max+1);
    for(int i=0;i<_max+1;i++){
        visited[i]=false;
    }
    visited[stpt]=true;
    int count=1,sum=0;
    while(not_done(visited,_max+1)){
        int num1,num2,min=9999;
        for(int i=0;i<candi.size();i++){
            for(int j=0;j<vec.size();j++){
                if(vec[j][0]==candi[i]){
                    if(vec[j][2]<min&&!visited[vec[j][1]]){
                        num1=vec[j][0];
                        num2=vec[j][1];
                        min=vec[j][2];
                    }
                }
                else if(vec[j][1]==candi[i]){
                    if(vec[j][2]<min&&!visited[vec[j][0]]){
                        num2=vec[j][0];
                        num1=vec[j][1];
                        min=vec[j][2];
                    }
                }
            }
        }
        visited[num2]=true;
        candi.push_back(num2);
        cout<<count<<": <"<<num1<<","<<num2<<">"<<endl;
        sum+=min;
        count++;
    }
    cout<<endl<<"The cost of minimum spanning tree: "<<sum<<endl;
}