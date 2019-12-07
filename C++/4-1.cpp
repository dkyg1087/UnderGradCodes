#include<iostream>
using namespace std;
int main(){
    int arr[60][60],size,dir,i,j,times=1,s_x,s_y;
    cin>>size>>dir;
    for(i=0,j=0;i<size&&j<size;j++){
        cin>>arr[i][j];
        if(j==size-1){
            j=-1;
            i++;
        }
    }
    cout<<arr[size/2][size/2];
    s_x=s_y=size/2;
    for(int k=1;;k++){
        switch(dir){
            case 0:
                for(i=1;i<=times;i++){
                    cout<<arr[s_x-i][s_y];
                    if(i==times){
                        s_x-=i;
                    }
                }
                break;
            case 1:
                for(j=1;j<=times;j++){
                    cout<<arr[s_x][s_y-j];
                    if(j==times){
                        s_y-=j;
                    }
                }
                break;
            case 2:
                for(i=1;i<=times;i++){
                    cout<<arr[s_x+i][s_y];
                    if(i==times){
                        s_x+=i;
                    }
                }
                break;
            case 3:
                for(j=1;j<=times;j++){
                    cout<<arr[s_x][s_y+j];
                    if(j==times){
                        s_y+=j;
                    }
                }
                break;
            default:
            cout<<"FAIL!!!!"<<endl;
            i=100;
            break;
        }
        if(k==2&&times!=size){
            k=0;
            times++;
        }
        dir=(dir+1)%4;
        if(times==size&&k==3)break;
    }
    cout<<endl;
    return 0;
}