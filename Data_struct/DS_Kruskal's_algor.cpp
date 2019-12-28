#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(vector<int>a,vector<int>b) {
    return a[2]<b[2];
}
bool check(int x, int y, vector<int> fam) {
	return fam[x] == fam[y] ? true : x == fam[y] ? true : y == fam[x] ? true : false;
}
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
void print(vector<int> fam) {
	for (int i = 0; i < fam.size(); i++) {
		if (fam[i] == i) {
			cout << " {" << i;
			for (int j = i+1; j < fam.size(); j++) {
				if (fam[j] == i)cout << "," << j;
			}
			cout << "}";
		}
	}
	cout << endl;
}
int main(){
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
    sort(vec.begin(),vec.end(),comp);
    int count=1,sum=0;
    vector<int>fam;
    for(int i=0;i<=_max;i++)fam.push_back(i);
    for(int i=0;i<vec.size();i++){
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