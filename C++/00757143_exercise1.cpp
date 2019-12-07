#include<iostream>
using namespace std;
int main(){
    int x;
    cin>>x;
    cin.get();
    for(;x>0;x--){
        char junk;
        int counter=0,couple=0;
        while(cin.get(junk)){
            if(junk=='p')counter++;
            else if(junk=='q'&&counter>0){
                counter--;
                couple++;
            }
            else if(junk=='\n')break;
        }
        cout<<couple<<"\n";
    }
    return 0;
}