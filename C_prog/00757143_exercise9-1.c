#include <stdio.h>
int gcd(int x, int y) {
    int t;
    while(x%y){
        t=x;
        x=y;
        y=t%y;
    }
    return y;
}
int main() {
    int n,i,j;
    int a[501]={},b[501][501]={};
    for(i = 1; i < 501; i++){
        for(j=i+1;j<501;j++){
            b[i][j]=b[i][j-1]+gcd(i, j);
            a[j]=a[j]+b[i][j];
        }
    }
    while(scanf("%d",&n)==1&&n){
        printf("%d\n",a[n]);
    }
    return 0;
}
