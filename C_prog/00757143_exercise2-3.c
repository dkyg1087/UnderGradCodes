#include<stdio.h>

int main()
{
  int n,m,c,a,temp;
  scanf("%d",&c);
  while (c > 0){
  scanf("%d%d",&n,&m);
       while (n>0){
       temp=temp*n;
       n=n-1;
       }
       a=temp%m;
  printf("%d\n",a);
       temp=a=1;
  c=c-1;   
  }

  return 0;
  }     
       