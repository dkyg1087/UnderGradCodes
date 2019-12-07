#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class matrix{
    public:
    int x;
    int y;
    int val;
};
bool cmp(matrix x,matrix y){
    if(x.y==y.y)return x.x<y.x;
    return x.y<y.y;
}
int main(){
    vector<matrix>ma;
    int row,col,num,x,y,val;
    cin>>row>>col>>num;
    int num2=num;
    while(num2--){
        matrix temp;
        cin>>temp.x>>temp.y>>temp.val;
        ma.push_back(temp);
    }
    sort(ma.begin(),ma.end(),cmp);
    cout<<row<<" "<<col<<" "<<num<<endl;
    for(int i=0;i<ma.size();i++){
        cout<<ma[i].y<<" "<<ma[i].x<<" "<<ma[i].val<<endl;
    }
}