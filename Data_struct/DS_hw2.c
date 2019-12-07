#include<stdio.h>
int main(){
    int num,p,count;
    scanf("%d",&num);
    for(p=2,count=0;p<num;p++){
        if(num%p==0){
            while(num%p==0){
                num/=p;
                count++;
            }
            if(count>1)printf("%d^%d",p,count);
            else printf("%d",p);
            if(num>1)printf(" * ");
            else {
                printf("\n");
                break;
            }
            count=0;
        } 
    }
    return 0;
}