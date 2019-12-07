#include<stdio.h>
#include<stdlib.h>
int main()
{
 int x,j,num,i,p,h,New,half;
 int sum=0;
 scanf("%d",&num);
 for(i=0;i<num;i++)
 {
  scanf("%d",&p);
  int a[30000];
  half=p/2;
 for(j=0;j<p;j++)
 {
  scanf("%d",&a[j]);
 }
 for(j=0;j<p;j++){
 for(x=j+1;x<p;x++)
 {
  if(a[j]<a[x])
  {
   h=a[j];
   a[j]=a[x];
   a[x]=h;
  }
 } 
 }
 New=a[half];
 for(j=0;j<p;j++)
 {
  sum=sum+abs(New-a[j]);
 }
 printf("%d\n",sum);
 sum=0;
 }
 return 0;
 
}