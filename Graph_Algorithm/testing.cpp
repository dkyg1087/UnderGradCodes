#include<iostream>
#include<algorithm>
#include<vector>
int  main(){
    std::vector <int> matrix;
    int n,m,temp;
    std::cin>>n>>m;
    while(std::cin>>temp){
        matrix.push_back(temp);
    }
    std::sort(matrix.begin(),matrix.end());
    std::cout<<matrix[m-1]<<std::endl;
}