#include<iostream>
using namespace std;
int arr[1200][1200];
int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        for(int i=0;i<1200;i++)for(int j=0;j<1200;j++)arr[i][j]=0;
        int range,num,x,y,val;
        cin>>range>>num;
        while(num--){
            cin>>x>>y>>val;
            for(int i=-1*range;i<=range;i++){
                for(int j=-1*range;j<=range;j++){
                    if(x+i<0||y+j<0||x+i>1200||y+j>1200)continue;
                    arr[x+i][y+j]+=val;
                }
            }
        }
        int max=0,temp_x,temp_y;
        for(int i=1199;i>=0;i--){
            for(int j=1199;j>=0;j--){
                if(arr[i][j]>=max){
                    max=arr[i][j];
                    temp_x=i;
                    temp_y=j;
                }
            }
        }
        cout<<temp_x<<" "<<temp_y<<" "<<max<<endl;
    }
}