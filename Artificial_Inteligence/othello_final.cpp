#include<iostream>
#include<limits>

#define MAX true
#define MIN false
#define SIZE 6

using namespace std;

int getStringPosistion(int i,int j);
pair<int,int> getBoardPosistion(int i);
int CountPlayerPieces(string,int);
int monteCarlo(string state,int player);
int opponentLeftMoves(string state,int player);
int getStateValue(string state,int player,int pos);
int getTableValue(int pos);
int countFlipPieces(string state,int player,int string_pos,int direction);
bool isLegalMove(string state,int player,int string_pos);
string flipPieces(string state,int player,int string_pos);


int getStringPosistion(int i,int j){
    return SIZE * i + j;
}

pair<int,int> getBoardPosistion(int i){
    int a,b;
    a = i/SIZE;
    b = i%SIZE;
    return make_pair(a,b);
}

int countPlayerPieces(string state,int player){
    char player_piece = player == 1 ? 'X' : 'O';
    int player_point = 0, opponent_point = 0;
    for(int i=0;i<state.length();i++){
        if(state[i] == player_piece)player_point++;
        else if (state[i]== '+')continue;
        else opponent_point++;
    }
    return player_point - opponent_point;
}

int opponentLeftMoves(string state,int player){
    int opponent = player == 1 ? 2 : 1;
    int count = 0;
    for(int i=0;i<state.length();i++){
        if(isLegalMove(state,opponent,i))count++;
    }
    return count;
}

int getStateValue(string state,int player,int pos){
    return getTableValue(pos) - 4* opponentLeftMoves(state,player) + 6 * countPlayerPieces(state,player);
}

int getTableValue(int pos){
    if(SIZE == 8){
        int table[64]={1000,-20,10,5,5,10,-20,1000,
                        -20,-50,-2,-2,-2,-2,-50,-20,
                        10,-2,-1,-1,-1,-1,-2,10,
                        5,-2,-1,-1,-1,-1,-2,5,
                        5,-2,-1,-1,-1,-1,-2,5,
                        10,-2,-1,-1,-1,-1,-2,10,
                        -20,-50,-2,-2,-2,-2,-50,-20,
                        1000,-20,10,5,5,10,-20,1000};
    return table[pos];
    }
    else{
        int table[36]={1000,-20,10,10,-20,1000,
                        -20,-50,-2,-2,-50,-20,
                        10,-2,-1,-1,-2,10,
                        10,-2,-1,-1,-2,10,
                        -20,-50,-2,-2,-50,-20,
                        1000,-20,10,10,-20,1000};
    return table[pos];
    }
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
        if(current_row < 0 || current_row >= SIZE || current_col < 0 || current_col >= SIZE){
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

bool isLegalMove(string state,int player,int string_pos){
    if(state[string_pos]!='+')return false;
    for(int i=0;i<8;i++)if(countFlipPieces(state,player,string_pos,i)>0)return true;
    return false;
}

string flipPieces(string state,int player,int string_pos){
    string result = state;
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
            current_pos += (SIZE*i+j);
            result[current_pos] = player == 1 ? 'X' : 'O';
        }
    }
    return result;
}


pair<int,int> getNextStep(string state,int player,int depth,bool targ,int real_player,int last_pos,int alpha,int beta,int skip_count){
    int flag = true;
    int value[SIZE*SIZE]={};
    int num = targ?-1000:1000;
    int move_set[SIZE*SIZE]={};
    int moves = 0;
    int current_alpha = alpha,current_beta = beta;
    for(int i = 0 ;i<state.length();i++)value[i]=num;
    for(int pos = 0 ;pos<state.length();pos++){
        if(isLegalMove(state,player,pos)){
            flag = false;
            move_set[moves++]=pos;
        }
    }
    // for(int i=0;i<moves;i++){
    //     if(move_set[i]==0){
    //         move_set[0]=0;
    //         moves=1;
    //         break;
    //     }
    //     if(move_set[i]==SIZE-1){
    //         move_set[0]=SIZE-1;
    //         moves=1;
    //         break;
    //     }
    //     if(move_set[i]==SIZE*SIZE-1){
    //         move_set[0]=SIZE*SIZE-1;
    //         moves=1;
    //         break;
    //     }
    //     if(move_set[i]==SIZE*SIZE-SIZE){
    //         move_set[0]=SIZE*SIZE-1;
    //         moves=1;
    //         break;
    //     }
    // }
    //if(depth >= 3)cout<<"Depth : "<<depth<<" Found moves "<<moves<<endl;
    // if(moves >= 8){
    //     cout<<moves<<endl;
    // }
    if(flag){
        if(skip_count >= 2){
            return make_pair(getStateValue(state,real_player,last_pos),last_pos);
            cout<<"skipped Twice!"<<endl;
        }
        return getNextStep(state,player == 1 ? 2 : 1,depth-1,!targ,real_player,last_pos,current_alpha,current_beta,++skip_count);
    }
    for(int i=0;i<moves;i++){
        if(skip_count>0)skip_count=0;
        if(current_alpha >= current_beta){
            //cout<<"pruned!!!!!"<<endl;
            return make_pair(targ?current_alpha:current_beta,last_pos);
        }
        if(depth <= 0){
            return make_pair(getStateValue(state,real_player,last_pos),last_pos);
        }
        else{
            if(targ){
                current_alpha = getNextStep(flipPieces(state,player,move_set[i]),player == 1 ? 2 : 1,depth-1,!targ,real_player,move_set[i],current_alpha,current_beta,skip_count).first;
                value[move_set[i]] = current_alpha;
            }
            else{
                current_beta = getNextStep(flipPieces(state,player,move_set[i]),player == 1 ? 2 : 1,depth-1,!targ,real_player,move_set[i],current_alpha,current_beta,skip_count).first;
                value[move_set[i]] = current_beta;
            }
        }   
    }
    int min_max = value[0];
    int string_pos = 0;
    for(int i=1;i<SIZE*SIZE;i++){
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
    return make_pair(min_max,string_pos);
}

bool isEnd(string state){
    for(int i=1;i<=2;i++){
        for(int j=0;j<SIZE*SIZE;j++){
            if(isLegalMove(state,i,j)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    string state = "+++++++++++++++++++++++++++OX++++++XO+++++++++++++++++++++++++++";
    if(SIZE == 6){
        state = "++++++++++++++OX++++XO++++++++++++++";
    }
    //++++++++++++++OX++++XO++++++++++++++
    string cmd;
    int BorW=0;
    cout<<"Do you want to be black or white (1 for black 2 for white)?"<<endl;
    cin>>BorW;
    while(true){
        if(BorW==1){
            if(isEnd(state)){
                int black=0,white=0;
                for(int i=0;i<SIZE*SIZE;i++){
                    if(state[i]=='X')black++;
                    if(state[i]=='O')white++;
                }
                cout<<"Game Ended "<<endl;
                cout<<"Black : "<<black<<endl;
                cout<<"White : "<<white<<endl;
                return 0;
            }
            while(cin>>cmd){
                if(cmd=="skip")break;
                int pos=getStringPosistion(cmd[0]-'A',cmd[1]-'a');
                state = flipPieces(state,1,pos);
                for(int i=0;i<SIZE*SIZE;i++){
                    if(i%SIZE==0)cout<<endl;
                    cout<<state[i]<<" ";
                }
                cout<<endl;
                break;
            }
            if(isEnd(state)){
                int black=0,white=0;
                for(int i=0;i<SIZE*SIZE;i++){
                    if(state[i]=='X')black++;
                    if(state[i]=='O')white++;
                }
                cout<<"Game Ended "<<endl;
                cout<<"Black : "<<black<<endl;
                cout<<"White : "<<white<<endl;
                return 0;
            }
            {
            pair<int,int> play = getNextStep(state,2,8,MAX,1,-1,INT32_MIN,INT32_MAX,0);
            state = flipPieces(state,2,play.second);
            char board_row = getBoardPosistion(play.second).first + 'A';
            char board_col = getBoardPosistion(play.second).second + 'a';
            cout<<"Player two plays "<<board_row<<board_col<<endl;
            for(int i=0;i<SIZE*SIZE;i++){
                if(i%SIZE==0)cout<<endl;
                cout<<state[i]<<" ";
            }
            cout<<endl;
            }
        }
        else if(BorW==2){
            if(isEnd(state)){
                int black=0,white=0;
                for(int i=0;i<SIZE*SIZE;i++){
                    if(state[i]=='X')black++;
                    if(state[i]=='O')white++;
                }
                cout<<"Game Ended "<<endl;
                cout<<"Black : "<<black<<endl;
                cout<<"White : "<<white<<endl;
                return 0;
            }
            {
            pair<int,int> play = getNextStep(state,1,8,MAX,1,-1,INT32_MIN,INT32_MAX,0);
            state = flipPieces(state,1,play.second);
            char board_row = getBoardPosistion(play.second).first + 'A';
            char board_col = getBoardPosistion(play.second).second + 'a';
            cout<<"Player two plays "<<board_row<<board_col<<endl;
            for(int i=0;i<SIZE*SIZE;i++){
                if(i%SIZE==0)cout<<endl;
                cout<<state[i]<<" ";
            }
            cout<<endl;
            }
            if(isEnd(state)){
                int black=0,white=0;
                for(int i=0;i<SIZE*SIZE;i++){
                    if(state[i]=='X')black++;
                    if(state[i]=='O')white++;
                }
                cout<<"Game Ended "<<endl;
                cout<<"Black : "<<black<<endl;
                cout<<"White : "<<white<<endl;
                return 0;
            }
            while(cin>>cmd){
                if(cmd=="skip")break;
                int pos=getStringPosistion(cmd[0]-'A',cmd[1]-'a');
                state = flipPieces(state,2,pos);
                for(int i=0;i<SIZE*SIZE;i++){
                    if(i%SIZE==0)cout<<endl;
                    cout<<state[i]<<" ";
                }
                cout<<endl;
                break;
            }
        }
        else{
            if(isEnd(state)){
                int black=0,white=0;
                for(int i=0;i<SIZE*SIZE;i++){
                    if(state[i]=='X')black++;
                    if(state[i]=='O')white++;
                }
                cout<<"Game Ended "<<endl;
                cout<<"Black : "<<black<<endl;
                cout<<"White : "<<white<<endl;
                return 0;
            }
            pair<int,int> play = getNextStep(state,1,7,MAX,1,-1,INT32_MIN,INT32_MAX,0);
            state = flipPieces(state,1,play.second);
            char board_row = getBoardPosistion(play.second).first + 'A';
            char board_col = getBoardPosistion(play.second).second + 'a';
            cout<<"Player one plays "<<board_row<<board_col<<" "<<play.first<<endl;
            for(int i=0;i<SIZE*SIZE;i++){
                if(i%SIZE==0)cout<<endl;
                cout<<state[i]<<" ";
            }
            cout<<endl;
            if(isEnd(state)){
                int black=0,white=0;
                for(int i=0;i<SIZE*SIZE;i++){
                    if(state[i]=='X')black++;
                    if(state[i]=='O')white++;
                }
                cout<<"Game Ended "<<endl;
                cout<<"Black : "<<black<<endl;
                cout<<"White : "<<white<<endl;
                return 0;
            }
            {
                pair<int,int> play = getNextStep(state,2,7,MAX,1,-1,INT32_MIN,INT32_MAX,0);
                state = flipPieces(state,2,play.second);
                char board_row = getBoardPosistion(play.second).first + 'A';
                char board_col = getBoardPosistion(play.second).second + 'a';
                cout<<"Player two plays "<<board_row<<board_col<<" "<<play.first<<endl;
                for(int i=0;i<SIZE*SIZE;i++){
                    if(i%SIZE==0)cout<<endl;
                    cout<<state[i]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
    }
}