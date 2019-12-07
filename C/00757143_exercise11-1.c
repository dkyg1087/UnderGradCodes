#include<stdio.h>
#include<math.h>
int main(){
    int x;
    float a,b,c,dis;
    scanf("%d",&x);
    scanf("%f %f %f",&a,&b,&c);
    for(;x>0;x--){
        float d,e;
        scanf("%f %f",&d,&e);
        dis=(a-d)*(a-d)+(b-e)*(b-e);
        dis=sqrt(dis);
        if(fabs(dis-c)>pow(10,-5)){
            if(dis-c>0)
            printf("-1\n");
            else
            printf("1\n");
        }
        else
        printf("0\n");
    }
    return 0;
}