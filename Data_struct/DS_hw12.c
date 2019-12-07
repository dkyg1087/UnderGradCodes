#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int search(char arr[][50],char c_arr[],int dir,int i,int j,int size){
    int k,count;
    for(count=k=0;count<strlen(c_arr);count++){
        switch (dir){
            case 1:
                if(i-count<0)k=i-count+size;
                else k=i-count;
                if(arr[k][j]!=c_arr[count])return 0;
                break;
            case 2:
                if(j+count>size)k=j+count-size;
                else k=j+count;
                if(arr[i][k]!=c_arr[count])return 0;
                break;
            case 3:
                if(j+count>size)k=i+count-size;
                else k=i+count;
                if(arr[k][j]!=c_arr[count])return 0;
                break;
            case 4:
                if(i-count<0)k=j-count+size;
                else k=j-count;
                if(arr[i][k]!=c_arr[count])return 0;
                break;
        }
    }
    return 1;
}
int main(){
    int size,targn,i,j;
    scanf("%d %d",&size,&targn);
    //char** arr=calloc(size,sizeof(char*));
    //for(i=0;i<size;i++)arr[i]=calloc(size,sizeof(char));
    char arr[50][50];
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            scanf("%c",&arr[i][j]);
            if(arr[i][j]=='\n'){
                scanf("%c",&arr[i][j]);
            }
        }
    }
    //char* c_arr=calloc(size,sizeof(char));
    char c_arr[50];
    getchar();
    for(;targn>0;targn--){
        fgets(c_arr,size,stdin);
        int flag=0;
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                if(arr[i][j]==c_arr[0]){
                    int k;
                    if(i-1<0)k=i-1+size;
                    else k=i-1;
                    if(arr[k][j]==c_arr[1])flag+=search(arr,c_arr,1,i,j,size);
                    if(i+1>size)k=i+1-size;
                    else k=i+1;
                    if(arr[k][j]==c_arr[1])flag+=search(arr,c_arr,3,i,j,size);
                    if(j+1>size)k=j+1-size;
                    else k=j+1;
                    if(arr[i][k]==c_arr[1])flag+=search(arr,c_arr,2,i,j,size);
                    if(j-1<0)k=j-1+size;
                    else k=j-1;
                    if(arr[i][k]==c_arr[1])flag+=search(arr,c_arr,4,i,j,size);
                if(flag>=1)goto Ans;
                }
            }
        }
        Ans:
        if(flag==0)printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}