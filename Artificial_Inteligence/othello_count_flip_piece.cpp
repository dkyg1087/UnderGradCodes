#include<iostream>
using namespace std;

class boardState{
    public:
        char currentboard[6][6];

        boardState(string str){
            int k=0;
            for(int i=0; i<6; i++){
                for(int j=0; j<6; j++){
                    this->currentboard[i][j] = str[k++];
                }
            }
        }
};

int countFlipPieces(string state,int player,char row,char column,int direction){
    int  i=0,j=0;
    switch(direction){
        case 0:
            i=-1;
            break;
        case 1:
            i=-1;
            j=1;
            break;
        case 2:
            j=1;
            break;
        case 3:
            i=1;
            j=1;
            break;
        case 4:
            i=1;
            break;
        case 5:
            i=1;
            j=-1;
            break;
        case 6:
            j=-1;
            break;
        case 7:
            i=-1;
            j=-1;
            break;
        default:
            cout<<"Direction Error"<<endl;
            return -1;
    }
    boardState* board = new boardState(state);
    int current_row = row - 'A';
    int current_col = column - 'a';
    int total=0;
    char opponent_piece = player == 1 ? 'O' : 'X';
    current_row+=i;
    current_col+=j;
    while(true){
        if(current_row < 0 || current_row >= 6 || current_col < 0 || current_col >= 6){
            total = 0;
            break;
        }
        if(board->currentboard[current_row][current_col]==opponent_piece)total++;
        else {
            if(board->currentboard[current_row][current_col]=='+')total = 0;
            break;
        }
        current_row+=i;
        current_col+=j;
    }
    return total;
}

int main(){
    int num;
    cin>>num;
    while(num--){
        string state;
        int player,direction;
        char row,column; 
        cin>>state>>player>>row>>column>>direction;
        cout<<countFlipPieces(state,player,row,column,direction)<<endl;
    }
}