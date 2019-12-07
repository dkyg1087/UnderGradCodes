#include<iostream>
using namespace std;
int main(){
    int N,i,l,r;
    cin>>N;
    int player[2][N],win[N]={};
    for(i=0;i<N;i++){
        cin>>player[0][i];
        cin>>player[1][i];
    }
    for(i=0;i<N;i++){
        for(l=1;i-l>=0;l++){
            if(player[0][i]>player[0][i-l]){
                if(player[1][i]>=player[1][i-l]){
                    win[i]++;
                }
                else break;
            }
            else if(player[0][i]==player[0][i-l]){
                if(player[1][i]>player[1][i-l]){
                    win[i]++;
                }
                else break;
            }
            else break;
        }
        for(r=1;i+r<N;r++){
            if(player[0][i]>player[0][i+r]){
                if(player[1][i]>=player[1][i+r]){
                    win[i]++;
                }
                else break;
            }
            else if(player[0][i]==player[0][i+r]){
                if(player[1][i]>player[1][i+r]){
                    win[i]++;
                }
                else break;
            }
            else break;
        }
    }
    int max=win[0];
    for(i=1;i<N;i++){
        if(win[i]>max)max=win[i];
    }
    cout<<max<<endl;
}