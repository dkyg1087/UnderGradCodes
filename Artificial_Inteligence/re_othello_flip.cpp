#include<iostream>
#include<utility>

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

int main(){
    int num;
    cin>>num;
    while(num--){
        string state;
        int player,direction;
        char row,column; 
        cin>>state>>player>>row>>column;
        cout<<flipPieces(state,player,getStringPosistion(row-'A',column-'a'))<<endl;
    }
}