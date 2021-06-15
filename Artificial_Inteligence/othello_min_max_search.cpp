#include<iostream>
#include<utility>
#include <iomanip>

#define MAX true
#define MIN false

using namespace std;

int getStringPosistion(int i,int j){
    return 6*i + j;
}

pair<int,int> getBoardPosistion(int i){
    int a,b;
    a = i/6;
    b = i%6;
    return make_pair(a,b);
}
int getStateValue(string state,int player){
    char player_piece = player == 1 ? 'X' : 'O';
    int player_point = 0, opponent_point = 0;
    for(int i=0;i<state.length();i++){
        if(state[i] == player_piece)player_point++;
        else if (state[i]== '+')continue;
        else opponent_point++;
    }
    // cout<<"counting state value for player "<<player<<" with a value of "<<player_point - opponent_point<<endl;
    return player_point - opponent_point;
}

int countFlipPieces(string state,int player,int string_pos,int direction){
    int total=0,current_row,current_col,i=0,j=0;
    pair<int,int>pos = getBoardPosistion(string_pos);
    current_row = pos.first;
    current_col = pos.second;
    char opponent_piece = player == 1 ? 'O' : 'X';
    if(direction<=1 || direction == 7)i=-1;
    else if(direction >=3 && direction<=5)i=1;
    if(direction>=5)j=-1;
    else if(direction>=1 && direction<=3)j=1;
    current_row+=i;
    current_col+=j;
    while(true){
        if(current_row < 0 || current_row >= 6 || current_col < 0 || current_col >= 6){
            total = 0;
            break;
        }
        if(state[getStringPosistion(current_row,current_col)]==opponent_piece)total++;
        else {
            if(state[getStringPosistion(current_row,current_col)]=='+')total = 0;
            break;
        }
        current_row+=i;
        current_col+=j;
    }
    return total;
}

string flipPieces(string state,int player,int string_pos){
    string result=state;
    result[string_pos]=player == 1 ? 'X' : 'O';
    for(int k=0;k<8;k++){
        int i=0,j=0;
        if(k<=1 || k == 7)i=-1;
        else if(k>=3 && k<=5)i=1;
        if(k>=5)j=-1;
        else if(k>=1 && k<=3)j=1;
        int times = countFlipPieces(state,player,string_pos,k);
        int current_pos = string_pos;
        while(times--){
            current_pos += (6*i+j);
            result[current_pos] = player == 1 ? 'X' : 'O';
        }
    }
    return result;
} 

bool isLegalMove(string state,int player,int string_pos){
    if(state[string_pos]!='+')return false;
    for(int i=0;i<8;i++)if(countFlipPieces(state,player,string_pos,i)>0)return true;
    return false;
}

pair<int,int> getNextStep(string state,int player,int depth,bool targ,int real_player){
    //cout<<"Getting the next step of player"<<player<<" on depth "<<depth<<" "<<(targ?"MAX":"MIN")<<" node"<<endl;
    if(depth == 0){
        return make_pair(getStateValue(state,real_player),0);
    }
    int flag=true;
    int value[36]={};
    int num = targ?-50:50;
    for(int i = 0 ;i<36;i++)value[i]=num;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            int pos = getStringPosistion(i,j);
            if(isLegalMove(state,player,pos)){
                // cout<<"player "<<player<<" found available move "<<i<<" "<<j<<endl;
                flag = false;
                if(depth == 0){
                    return make_pair(getStateValue(flipPieces(state,player,pos),real_player),pos);
                }
                else{
                    value[pos] = getNextStep(flipPieces(state,player,pos),player == 1 ? 2 : 1,depth-1,!targ,real_player).first;
                }
                
            }
        }
    }
    if(flag){
        return getNextStep(state,player == 1 ? 2 : 1,depth-1,!targ,real_player);
    }
    int min_max = value[0];
    int string_pos = 0;
    for(int i=1;i<36;i++){
        if(targ){
            if(value[i] > min_max){
                min_max = value[i];
                string_pos = i;
            }
        }
        else{
            if(value[i] < min_max){
                min_max = value[i];
                string_pos = i;
            }
        }
    }
    // cout<<"find "<<(targ?"MAX":"MIN")<<" value of "<<min_max<<" on depth "<<depth<<endl;
    // for(int i=0;i<36;i++){
    //     if(i%6==0)printf("\n");
    //     printf("%5d ",state[i]=='+'?value[i]:state[i]=='O'?200:100);
    // }
    // cout<<endl<<endl;
    return make_pair(min_max,string_pos);
}

int main(){
    int num=0;
    cin>>num;
    while(num--){
        string state;
        int player,depth;
        cin>>state>>player>>depth;
        int pos = getNextStep(state,player,depth,MAX,player).second;
        char board_row = getBoardPosistion(pos).first + 'A';
        char board_col = getBoardPosistion(pos).second + 'a';
        cout<<board_row<<board_col<<endl;
    }
}