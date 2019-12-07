#include<stdio.h>
int a[23][23]={0},r,c,r1,c1,i,j,bw,ch;
int main(){
    for(;;){
        for(bw=1;bw<=10;bw=bw+9){
            scanf("%d,%d",&r,&c);
            a[r][c]=bw;
            for(i=0,j=0,r1=0,c1=0;j<19;i++,j++){
                if(a[r][j]>0){
                    r1++;
                }
                if(a[i][c]>0){
                    c1++;; 
                }
            }
            printf("%d:%d %d:%d\n",r,r1,c,c1);
            for(ch=4;ch>=0;ch--){
                if(a[r][c-ch]+a[r][c-ch+1]+a[r][c-ch+2]+a[r][c-ch+3]+a[r][c-ch+4]==bw*5||a[r-ch][c]+a[r-ch+1][c]+a[r-ch+2][c]+a[r-ch+3][c]+a[r-ch+4][c]==bw*5||a[r-ch][c-ch]+a[r-ch+1][c-ch+1]+a[r-ch+4][c-ch+4]+a[r-ch+2][c-ch+2]+a[r-ch+3][c-ch+3]==bw*5||a[r-ch][c+ch]+a[r-ch+1][c+ch-1]+a[r-ch+2][c+ch-2]+a[r-ch+3][c+ch-3]+a[r-ch+4][c+ch-4]==bw*5){
                    goto print ;
                }
            } 
        }
    }
    print:
    if(bw==1){
        printf("black\n");
    }
    else{
        printf("white\n");
    }
    return 0;
}
