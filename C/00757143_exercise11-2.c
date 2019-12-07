#include<stdio.h>
int main(){
    int x,i,j;
    scanf("%d",&x);
    float a[x],b[x],temp1,temp2;
    for(i=0;i<x;i++){
        scanf("%f %f",&a[i],&b[i]);
    }
    for(i=0;i<x-1;i++){
        for(j=0;j<x-i-1;j++){
            if(a[j]>a[j+1]){
                temp1=a[j];
                temp2=b[j];
                a[j]=a[j+1];
                b[j]=b[j+1];
                a[j+1]=temp1;
                b[j+1]=temp2;
            }
        }
    }
    for(i=0;i<x-1;i++){
        if(a[i]==a[i+1]&&b[i]>b[i+1]){
            temp2=b[i];
            b[i]=b[i+1];
            b[i+1]=temp2;
        }
    }
    for(i=0;i<x;i++){
        printf("%.2f %.2f\n",a[i],b[i]);
    }
    return 0;
}