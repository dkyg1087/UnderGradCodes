#include <iostream>
int main(){
    int num,start,end,end_now=-1;
    while(!std::cin.eof()){
        std::cin>>num>>start>>end;
        if(end_now<=start){
            std::cout<<num<<" ";
            end_now=end;
        }
    }
    std::cout<<std::endl;
    return 0;
}