#include<iostream>
using namespace std;
int count_tree(int num){
    if(num<=1)return 1;
    else{
        int left,right,sum=0;
        num=num-1;
        for(int leftnum=0;leftnum<=num;leftnum++){
            left=count_tree(leftnum);
            right=count_tree(num-leftnum);
            sum+=left*right;
        }
        return sum;
    }
}
int main(){
    int num=3;
    cout<<count_tree(num)<<endl;
    return 0;
}