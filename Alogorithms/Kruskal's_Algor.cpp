#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<array>
using namespace std;
void _union(int x, int y, vector<int> &fam) {
	if (fam[x] > fam[y]) {
		int temp = fam[x];
		for (int i = 0; i < fam.size(); i++)if (fam[i] == temp)fam[i] = fam[y];
	}
	else {
		int temp = fam[y];
		for (int i = 0; i < fam.size(); i++)if (fam[i] == temp)fam[i] = fam[x];
	}
}
bool check(int x, int y, vector<int> fam) {
	return fam[x] == fam[y] ? true : x == fam[y] ? true : y == fam[x] ? true : false;
}
bool cmp(array<int,3> a,array<int,3> b){
    return a[0]==b[0]?a[1]<b[1]:a[0]<b[0];
}
bool cmp2(array<int,3> a,array<int,3> b){
    return a[2]==b[2]?a[0]==b[0]?a[1]<b[1]:a[0]<b[0]:a[2]<b[2];
}
int main(){
    int maxNode=0,count=1,sum=0;
    array<int,3>temp;
    vector<array<int,3>>vec;
    while(cin>>temp[0]>>temp[1]>>temp[2]){
        maxNode=max(temp[0],max(temp[1],maxNode));
        vec.push_back(temp);
        swap(temp[0],temp[1]);
        temp[2]=INT_MAX;
        vec.push_back(temp);
    }
    sort(vec.begin(),vec.end(),cmp);
    cout<<"Adjacency list:"<<endl;
    for(int i=0,j=0;i<=maxNode;i++){
        cout<<i<<": ";
        for(;j<vec.size();j++){
            if(vec[j][0]==i)cout<<vec[j][1]<<" -> ";
            else break;
        }
        cout<<"end"<<endl;
    }
    cout<<endl<<"minimum spanning tree:"<<endl;
    sort(vec.begin(),vec.end(),cmp2);
    vector<int>fam;
    for(int i=0;i<=maxNode;i++)fam.push_back(i);
    for(int i=0;i<vec.size()&&count<=maxNode;i++){
        if(!check(vec[i][0],vec[i][1],fam)){
            cout<<count<<": <"<<vec[i][0]<<","<<vec[i][1]<<">"<<endl;
            sum+=vec[i][2];
            _union(vec[i][0],vec[i][1],fam);
            count++;
        }
        else continue;
    }
    cout<<endl<<"The cost of minimum spanning tree: "<<sum<<endl;
}