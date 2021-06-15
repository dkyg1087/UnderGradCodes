#include<iostream>
using namespace std;
int countPlayerPieces(string state,int player){
    char player_piece = player == 1 ? 'X' : 'O';
    int  total=0;
    for(int i=0;i<state.length();i++)if(state[i] == player_piece)total++;
    return total;
}
int main(){
    int num;
    cin>>num;
    while(num--){
        string state;
        int player,direction;
        cin>>state>>player;
        cout<<countPlayerPieces(state,player)<<endl;
    }
}