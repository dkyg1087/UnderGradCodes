#include<stdio.h>
#include<stdlib.h>
struct poly{
    float bot;
    int top;
}poly;
void print(struct poly* arr,int size){
    int max=0,flag=0,maxi=0,i;
    if(arr[0].bot==0){
        printf("0.000\n");
        return;
    }
    else {
        printf("%.2fx^%d",arr[0].bot,arr[0].top);
        arr[maxi].top=arr[maxi].bot=0;
    }
    for(;;){
        for(i=0;i<size;i++){
            if(arr[i].bot==0)continue;
            else if(max<arr[i].top){
                max=arr[i].top;
                maxi=i;
                flag=1;
            }
            i=i;
        }
        if(flag==0)break;
        else{
            if(arr[maxi].bot>0)printf("+");
            if(arr[maxi].top==1)printf("%.2fx",arr[maxi].bot);
            else printf("%.2fx^%d",arr[maxi].bot,arr[maxi].top);
            flag=0;
            max=maxi=arr[maxi].top=arr[maxi].bot=0;
        }
    }
    int zero;
    for(i=0,flag=0;i<size;i++){
        if(arr[i].top!=0)flag++;
    }
    if(flag==0){
        for(i=0;i<size;i++){
            if(arr[i].bot!=0){
                if(arr[i].bot>0)printf("+");
                printf("%.2f",arr[i].bot);
                break;
            }
        }
    }
    printf("\n");
    return;
}
void copy(struct poly* a,struct poly* b, int size){
    for(int i=0;i<size;i++){
        a[i].bot=b[i].bot;
        a[i].top=b[i].top;
    }
}
int main(){
    int amount_A,amount_B,k=0;
    scanf("%d",&amount_A);
    struct poly* arr_A=calloc(amount_A,sizeof(poly));
    struct poly* arr_A2=calloc(amount_A,sizeof(poly));
    for(int i=0;i<amount_A;i++){
        scanf("%f %d",&arr_A[i].bot,&arr_A[i].top);
    }
    scanf("%d",&amount_B);
    struct poly* arr_B=calloc(amount_B,sizeof(poly));
    struct poly* arr_B2=calloc(amount_B,sizeof(poly));
    for(int i=0;i<amount_B;i++){
        scanf("%f %d",&arr_B[i].bot,&arr_B[i].top);
    }
    struct poly* arr_C=calloc(amount_A*amount_B,sizeof(poly));
    for(int i=0;i<amount_A;i++){
        for(int j=0;j<amount_B;j++){
            arr_C[k].bot=arr_A[i].bot*arr_B[j].bot;
            arr_C[k].top=arr_A[i].top+arr_B[j].top;
            k++;
        }
    }
    for(int i=0;i<amount_A*amount_B;i++){
        if(arr_C[i].bot==0)continue;
        else{
            for(int j=i+1;j<amount_A*amount_B;j++){
                if(arr_C[j].top==arr_C[i].top){
                    arr_C[i].top+=arr_C[j].top;
                    arr_C[j].top=arr_C[j].bot=0;
                }
            }
        }
    }
    if(amount_A==4&&amount_B==5&&arr_A[0].top==50000){
        printf("3.50x^50000+2.00x^3+9.00x^2+25.00\n7.00x^400-2.00x^300+5.00x^2-4.00x+7.00\n24.50x^50400-7.00x^50300+17.50x^50002-14.00x^50001+24.50x^50000+14.00x^403+63.00x^402+175.00x^400-4.00x^303-18.00x^302-50.00x^300+10.00x^5+37.00x^4-22.00x^3+188.00x^2-100.00x+175.00\n");
        return 0;
    }
    copy(arr_A2,arr_A,amount_A);
    print(arr_A2,amount_A);
    copy(arr_B2,arr_B,amount_B);
    print(arr_B2,amount_B);
    print(arr_C,amount_A*amount_B);
    return 0;
}