#include <stdio.h>
int main()
{
unsigned long int x,y;
int c=0,r,s=0;
for(;;){
    scanf("%lu%lu",&x,&y);
    if(x==0&&y==0){
        break;
    }
    while(x!=0 && y!=0){
    r=(x%10)+(y%10)+s;
    s=0;
    if(r>=10){
        c++;
        s=1;
    }
    x/=10;
    y/=10;
    }
    if(c==0){
        printf("No carry operation.\n");
    }
    else if(c==1){
        printf("1 carry operation.\n");
    }
    else{
        printf("%d carry operations.\n",c);
    }
    c=0;    
}
return 0;
}