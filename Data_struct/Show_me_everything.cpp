#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    char junk;
    int i=0;
    while(scanf("%c",&junk)==1){
        i++;
        if(junk=='\n')printf("'\\n'->No.%d\n",i);
        else if(junk=='\r')printf("'\\r'->No.%d,",i);
        else printf("'%c'->No.%d,",junk,i);
    }
}