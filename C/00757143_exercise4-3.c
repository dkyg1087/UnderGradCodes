#include <stdio.h>

int main()
{
    int c[1000],n,h,i,a,C=0,f=0;
    scanf("%d%d",&n,&h);
    for(i=0;i<n;i++){
        scanf("%d",&c[i]);
    }
    for(i=0;i<n;i++){
        for(a=(i-h),C=0;a<=(i+h);a++){
            if(a<0){
                if(c[i]<c[0]){
                C=1;
                goto check ;
            }
            }
            if(a>(n-1)){
                if(c[i]<c[n-1]){
                C=1;
                goto check ;
                    }
            }
            
            if(c[i]<c[a]){
                C=1;
            }
            check:
            if(C==1){
                break;
            }
        }
        if(C==0 && f==0){
        printf("%d",i);
        f=1;
        }
        else if(C==0 && f==1){
            printf(",%d",i);
        }
        
    }
    printf("\n");
    return 0;
}