#include<stdio.h>
unsigned char id[10001];
int main()
{
    int N,R,i,d;
    while(scanf("%d%d",&N,&R)==2) {
        for(i = 1; i <= N; ++i) {
            id[i] = 1; 
        }
          d=R;
          while(d!=0){
             scanf("%d",&i);
             id[i]=0;
             d--;
          }
         if(N==R){
          printf("*");
          goto print ;
         }
         for(i=1; i<=N;i++) {
             if(id[i]==1){
                 printf("%d ",i);
                 id[i]=0;
             } 
         }
         print: 
          printf("\n");
    }
    return 0;
}