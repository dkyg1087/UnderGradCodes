#include<stdio.h>
int main(){
    int c,i,j,k;
    
    char junk[300];
    int flag=0;
    scanf("%d",&c);
    gets(junk);
    for(;c>0;c--){
     
        char a[256]={},b[256]={};
        gets(a);
        gets(b);
        for(i=255;i>0;i--){
            if(a[i-1]==46&&a[i]==99){
            flag=1;
            }
        }
        
        for(i=255;i>=0;i--){
            if(a[i]==58||a[i]==92||i==0)
            break;
        }
        for(j=0;j<=i;j++){
            if(i==0) break;
            printf("%c",a[j]);
     }
  if(flag==1)printf("%s.c\n",b);
        else printf("%s\n",b);
  flag =0;
    }
    return 0;
}