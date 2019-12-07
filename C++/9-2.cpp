#include<iostream>
#include<vector>
using namespace std;
int main(){
    int counter=1;
    char ind,ch;
    while(cin>>ind){
        vector<char> Vec;
        Vec.push_back(ind);
        for(;;){
            cin.get(ch);
            if(ch=='\n')break;
            else Vec.push_back(ch);
        }
        cout<<"AB Circle #"<<counter<<":"<<endl;
        int start,end;
        for(start=0;start<Vec.size()-1;start++){
            for(end=start+1;end<Vec.size();end++){
                int left_A=0,right_A=0,left_B=0,right_B=0,i;
                for(i=start;i<end;i++){
                    if(Vec[i]=='a')left_A++;
                    else left_B++;
                }
                for(i=0;i<start;i++){
                    if(Vec[i]=='a')right_A++;
                    else right_B++;
                }
                for(i=end;i<Vec.size();i++){
                    if(Vec[i]=='a')right_A++;
                    else right_B++;
                }
                if(left_A==right_B||left_B==right_A)cout<<start<<","<<end<<endl;
            }
        }
        cout<<endl;
        counter++;
    }
    return 0;
}