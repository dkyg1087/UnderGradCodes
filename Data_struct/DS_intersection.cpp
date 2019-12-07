#include<iostream>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<cmath>
#include<string.h>
#include<vector>
int main(){
    std::vector<int>vec;
    std::string str;
    std::getline(std::cin,str);
    char* token;
    token = strtok(&str[0]," ");
    while(token!=NULL){
        vec.push_back(atoi(token));
        token=strtok(NULL," ");
    }
    int *arr=new int[vec[0]];
    for(int i=0;i<vec[0];i++)arr[i]=0;
    int k=0; 
    for(int i=1;i<vec.size();i++){
        for(int j=0;j<vec[i];j++){
            arr[k++]=1;
        }
        k++;
    }
    int sum=0,space;
    for(int i=1;i<vec.size();i++)sum+=vec[i];
    space=vec[0]-(vec.size()-2)-sum;
    int t_space=space;
    for(int i=0;i<vec[0];i++){
        if(arr[i]==1&&t_space>0){
            arr[i]=0;
            t_space--;
        }
        else if(arr[i]==0&&t_space>=0){
            t_space=space;
        }
    }
    std::cout<<arr[0];
    for(int i=1;i<vec[0];i++)std::cout<<" "<<arr[i];
    std::cout<<std::endl;
}
