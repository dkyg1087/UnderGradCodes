#include<iostream>
using namespace std;
int main(){
    double a = 250.93,b = 195.22 ,c = 99.45;
    double goal1 = 1505.8364 ,goal2 = 1343.2966;
    double goal3 = goal1 * 3.0, goal4 = goal2 * 3.0; 
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            for(int k=0 ;k<20;k++){
                if(i-k == 3){
                    double outcome = i*a + j*b + c*k;
                    if(goal3-15 < outcome && goal3+15 > outcome )cout<<goal3<<" : "<<i<<" "<<j<<" "<<k<<" "<< outcome <<endl;
                    if(goal4-15 < outcome && goal4+15 >outcome)cout<<goal4<<" : "<<i<<" "<<j<<" "<<k<<" "<< outcome <<endl;
                }
                if(i - k ==1){
                    double outcome = i*a + j*b + c*k;
                    if(goal1-15 < outcome && goal1+15 > outcome )cout<<goal1<<" : "<<i<<" "<<j<<" "<<k<<" "<< outcome <<endl;
                    if(goal2-15 < outcome && goal2+15 >outcome)cout<<goal2<<" : "<<i<<" "<<j<<" "<<k<<" "<< outcome <<endl;
                }
            }
        }
    }
}