#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
    int num,count=1;
    cin>>num;
    cout<<"SOLN       COLUMN"<<endl<<" #      1 2 3 4 5 6 7 8"<<endl;
    while(num--){
        int row,col;
        cin>>row>>col;
        vector<int>chess;
        for(int i=1;i<=8;i++)chess.push_back(i);
        chess.erase(chess.begin()+col-1);
        chess.insert(chess.begin()+row-1,col);
        while(next_permutation(chess.begin(),chess.end())){
            int flag=0;
            for(int i=0;i<7;i++){
                for(int j=0;j<7;j++){
                    if((chess[i]-chess[j])/(i-j)==1||(chess[i]-chess[j])/(i-j)==-1){
                        flag=1;
                        break;
                    }
                }
                if(flag==1)break;
            }
            if(flag==0){
                cout<<count++<<"       "<<chess[0];
                for(int i=1;i<7;i++){
                    cout<<" "<<chess[i];
                }
                cout<<endl;
            }
        }

    }
}