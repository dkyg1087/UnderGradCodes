#include<iostream>
using namespace std;
int main(){
    int i,arr[3][4]={1,1,1,9, //x+y+z=9    答案為x=2,y=3,z=4
                   3,5,3,33,//3x+5y+3z=33
                   2,3,5,33};//2x+3y+5z=33
    /*確認第一列第一個元素是否為1，不為1則使其變1或從其他行換1過來*/
    while(arr[1][0]!=0){
        for(i=0;i<4;i++){
            arr[1][i]-=arr[0][i];
        }
    }
    while(arr[2][0]!=0){
        for(i=0;i<4;i++){
            arr[2][i]-=arr[0][i];
        }
    }//將第1行的剩下元素歸0
    if(arr[1][1]!=0){
        int a=arr[1][1];
        for(i=1;i<4;i++){
                arr[1][i]/=a;
        }
    }//將第二列第二行元素變成1
    while(arr[2][1]!=0){    
        for(i=1;i<4;i++){
            arr[2][i]-=arr[1][i];
        }
    }
    if(arr[2][2]!=0){
        int a=arr[2][2];
        for(i=2;i<4;i++){
                arr[2][i]/=a;
        }
    }//下半完成
    while(arr[1][2]!=0){
        for(i=0;i<4;i++){
            arr[1][i]-=arr[2][i];
        }
    }//清除第三col.
    while(arr[0][2]!=0){
        for(i=0;i<4;i++){
            arr[0][i]-=arr[2][i];
        }
    }
    while(arr[0][1]!=0){
        for(i=0;i<4;i++){
            arr[0][i]-=arr[1][i];
        }
    }
    cout<<"Answer is:"<<endl;
    for(i=0;i<3;i++){
        cout<<"       "<<arr[i][3]<<endl;
    }
    cin.get();
    return 0;
}   
