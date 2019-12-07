#include<iostream>
#include<string>
using namespace std;
int main(){

}
int search(char arr[][50],string c_arr,int dir,int i,int j,int size){
    int k,count;
    for(count=0;count<c_arr.size();count++){
        switch(dir){
            case 1:
                if(i-count<0)k=i-count+size;
                else k=i-count;
                if(arr[k][j]!=c_arr[count])return 0;
                break;
            case 2:
                if(j+count>size)k=j+count-size;
                else k=j+count;
                if(arr[i][k]!=c_arr[count])return 0;
        }
    }
}