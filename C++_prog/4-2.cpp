#include<iostream>
#include<stdio.h>
using namespace std;
int move(int x,int a[]);
int main(){
    char p_stat[9][7];
    int i,t,c,s,outs;
    for(i=0;i<9;i++){
        cin>>t;
        for(c=0,s=t;s>0;s--,c++){
            cin.get();
            cin.get(p_stat[i][c]);
            cin.get();
        }
    }
    cin>>outs;
    int points=0,temp=0,base[4]={};
    for(c=0,s=0,i=0;outs>0;i++){
        if(isalpha(p_stat[i][s])&&p_stat[i][s]!='H'){
            outs--;
            c++;
            if(c==3){
                c=0;
                for(int i=0;i<4;i++)base[i]=0;
            }
        }
        else{
            int x;
            if(p_stat[i][s]!='H') x=p_stat[i][s]-'0';
            else x=4;
            points+=move(x,base);
        }
        if(i==8){
            i=-1;
            s++;
        }
    }
    cout<<points<<endl;
    return 0;
}
int move(int x,int a[]){
    int i,counter=0;
    for(i=0;i<4;i++){
        if(a[i]!=0){
            a[i]+=x;
        }
    }
    for(i=0;i<4;i++){
        if(a[i]==0){
            a[i]=x;
            break;
        }
    }
    for(i=0;i<4;i++){
        if(a[i]>=4){
            a[i]=0;
            counter++;
        }
    }
    return counter;
}
