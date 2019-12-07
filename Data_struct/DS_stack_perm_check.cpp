#include<iostream>
#include<stack>
#include<string>
int main(){
    int size,fnum;
    std::string str="1";
    std::cin>>size;
    for(int i=2;i<=size;i++)str.append(std::to_string(i));
    while(std::cin>>fnum,fnum!=-1){
        std::stack<char>stk;
        std::string ans;
        ans=std::to_string(fnum);
        int i=0,j=0;
        for(int i=1;i<size;i++){
            std::cin>>fnum;
            ans.append(std::to_string(fnum));
        }
        int flag=1;
        while(i<size){
            if(ans[i]==(j<size?str[j]:0)){
                    i++;
                    j++;   
            }
            else if(ans[i]==(stk.size()>0?stk.top():0)){
                    stk.pop();
                    i++;   
            }
            else {
                if(j>=size&&stk.top()!=ans[i]){
                    flag=0;
                    break;
                }
                stk.push(str[j++]);

            }
        }
        if(flag==0)std::cout<<"NO"<<std::endl;
        else std::cout<<"YES"<<std::endl;
    }
}