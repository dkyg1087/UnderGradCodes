#include<stdio.h>  
  
int main(){  
  
unsigned long int x,a,b,c;

while(scanf("%lu",&x)!=EOF){

if (x<1000){
printf("%lu\n",x);
}
else if (x<1000000 && x>=1000){
a=x%1000;
x=x/1000;
printf("%lu,%003lu\n",x,a);
}

else if (x<1000000000 && x>=1000000){
a=x%1000;
x=x/1000;
b=x%1000;
x=x/1000;
printf("%lu,%003lu,%003lu\n",x,b,a);
}
else {
a=x%1000;
x=x/1000;
b=x%1000;
x=x/1000;
c=x%1000;
x=x/1000;
printf("%lu,%003lu,%003lu,%003lu\n",x,c,b,a);
}
}
return 0;
}