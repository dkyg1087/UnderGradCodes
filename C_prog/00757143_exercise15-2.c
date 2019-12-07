#include<stdio.h>  
int main(){  
    int y,m,d;  
    scanf("%d-",&y);  
    for(;;){  
        int i,c;  
        float a[100]={0};  
        char junk='a';  
        if(scanf("%d-%d",&m,&d)!=2)break;  
        printf("%d/%d/%d",y,m,d);  
        for(i=0;;){  
            if(scanf("%f",&a[i])!=1){  
                if(scanf("%c",&junk)==EOF) break;;  
            }  
            else{   
                scanf("%c",&junk);  
                i++;  
            }  
            if(junk==45){  
                 y=(int)a[i-1];  
                 break;  
            }  
        }  
        for(c=0;c<i-1;c++){  
            printf(" %.2f",a[c]);  
        }  
        printf("\n");  
    }  
    return 0;  
}  