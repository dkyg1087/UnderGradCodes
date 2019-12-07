#include<stdio.h>
int main(){
    int a[10][10],n1,x,y,v,i;
    scanf("%d",&n1);
    for(i=0;i<n1;i++){
        scanf("(%d:%d)=%d",&x,&y,&v);
        a[x][y]=v;    
    }
    printf("%d",a[x][y]);
}