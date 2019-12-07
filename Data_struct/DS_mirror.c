#include<stdio.h>
#include<string.h>
int main(){
    int stack=0;
    char temp;
    char a[300];
    for(;;){
        for(;;){
            if(stack<0){
                printf("-1\n");
                goto END;
            }
            scanf("%c",&temp);
            switch (temp){
                case '(':
                    stack++;
                    break;
                case ')':
                    stack--;
                    break;
                case '\n':
                    goto PRINT ;
                case 'e':
                    goto ENDD ;
            }
        }
        PRINT:
            if(stack!=0)printf("-1\n");
            else printf("1\n");
            continue;
        END:
        stack=0;
        scanf("%s",&a);
    }
    ENDD:
    return 0;
}