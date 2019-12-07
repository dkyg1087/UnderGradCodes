#include<stdio.h>
int main()
{
 int a,b,i,c,t;
 scanf("%d%d%d",&i,&a,&b);
 int d[i+1];
 t=i;
 for(i=i+1;i>=0;i--){
     d[i]=0;
 }
 for(i=t;i!=0;i--){
     scanf("%d",&c);
     d[c]++;
    }
 for(i=a;i<=b;i++){
     printf("%d appears %d times\n",i,d[i]);
 }
 return 0;   
}
