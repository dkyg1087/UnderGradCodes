#include<stdio.h>
int main(){
    char a[500]={};
    while(gets(a)!=NULL){
        int i,j;
        for(i=0;;){
            for(j=i;j<findmy(a,i)&&j<strlen(a);j++){
                printf("%c",a[j]);
            }
            i=findmy(a,i);
            if(i==1000)break;
            if(a[i]=='M') printf("Your");
            else printf("your");
            i=i+2; 
        }
        printf("\n");
    }
    return 0;
}
int findmy(const char* a,int x){
    for(;x<strlen(a);x++){
        if((a[x]=='M'||a[x]=='m')&&a[x+1]=='y')
        return x;
    }
    return 1000;
}