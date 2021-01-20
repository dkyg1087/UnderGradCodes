#include<stdio.h>
int main()
{
    int n,i,r,number[30000],j,m,temp,diff,sum,min_sum,min_number;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    { 
        scanf("%d",&r);
        for(j=0;j<r;j++)
        {
            scanf("%d",&number[j]);
        }
        for(m=1;m<j-1;m++)//bubble sort 由小到大 
        {
            for(int n=m+1;n<j;n++)
            {
                if(number[n]<number[m])
                {
                    temp=number[n];
                    number[n]=number[m];
                    number[m]=temp;
                }
            } 
        }
        //求中值
        sum=0;
        min_sum=2147483647;
        for(m=number[1];m<=number[j-1];m++)
        {
            for(int n=1;n<j;n++)
            {
                diff=m-number[n];
                if(diff<0) diff=-diff;
                sum+=diff;
                if(n==(j-1))
                {
                    if(sum<min_sum)
                    {
                        min_sum=sum;
                        min_number=m;
                    }
                    sum=0;
                }
            }
        }
        printf("%d\n",min_number);
    } 
    return 0;
}