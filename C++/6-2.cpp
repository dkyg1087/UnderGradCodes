#include<iostream>
using namespace std;
int main(){
    int counter;
    for(counter=1;;counter++){
        char arr[22][22]={},t;
        int r,c,i,j,x,z,trash=100;
        cin>>r>>c;
        if(counter!=1){
            if(r!=0||c!=0){
                cout<<endl;
            }
        }
        if(r==0||c==0){
            break;
        }
        for(i=1,j=1;i<=r&&j<=c;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='.'){
            arr[i][j]='0';
            }
            if(j==c){
            i++;
            j=0;
            }   
        }
        for(i=1,j=1;i<=r&&j<=c;j++){
            if(arr[i][j]=='*'){
                for(z=-1;z<2;z++){
                    for(x=-1;x<2;x++){
                        if(arr[i+z][j+x]!='*'){
                            arr[i+z][j+x]++;
                        }
                    }
                }
            }
            if(j==c){
                i++;
                j=0;
            }
        }
        cout<<"Field #"<<counter<<":"<<endl;
        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                cout<<arr[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}