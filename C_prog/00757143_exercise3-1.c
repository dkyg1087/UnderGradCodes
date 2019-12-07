#include<stdio.h>

int main(){

    int y,a,b,c;
    while(scanf("%d",&y)!=EOF){
               a=y%4;
               b=y%400;               
               c=y%100;
               if(a!=0){
                 printf("nonleap\n");
                 }
               else if(b==0){
                 printf("leap\n");
                 }
               else if(c==0){
                 printf("nonleap\n");
                 }
               else{
                 printf("leap\n");
                 }
    }
    return 0;
}