#include<stdio.h>  
int main()  
{  
 int a,b,c,i,t;  
 scanf("%d%d%d",&i,&a,&b);  
 int d[b+1];   
 for(t=b;t>=0;t--){  
     d[t]=0;  
 }  
 for(;i>0;i--){  
     scanf("%d",&c);  
     d[c]++;  
    }  
 for(i=a;i<=b;i++){  
     printf("%d appears %d times\n",i,d[i]);  
 }  
 return 0;     
} 