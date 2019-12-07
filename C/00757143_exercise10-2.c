#include <stdio.h>
#include<math.h>

int main()
{
int a,b,c,d,i,j;
while(scanf("%d",&a)==1){
    int e[4]={0};
    for(b=1,c=0;b<=a;b++){
        if(a%b==0)c++;
        if(c>2)break;
    }
    if(c>2){
        c=0;
        printf("%d is not prime.\n",a);
    }
    else if(c==2){
        for(b=a,i=0;b>0;i++){
            e[i]=b%10;
            b/=10;
        }
        for(d=0,j=i,i=0;i<5;i++,j--){
            d+=e[i]*pow(10,j);
        }
        d/=10;
        if(a==d) goto same ;
        for(b=1,c=0;b<=d;b++){
        if(d%b==0)c++;
        if(c>2)break;
    }
    if(c==2){
        c=0;
        printf("%d is emirp.\n",a);
    }
    else 
    same:
    printf("%d is prime.\n",a);
    }
}
return 0;
}