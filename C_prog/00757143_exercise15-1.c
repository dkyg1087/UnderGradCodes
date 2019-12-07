#include<stdio.h>
struct record {
    char msg[8];
    unsigned next;
};
int main(){
    FILE* fp = stdin;
    if(freopen(NULL,"rb",fp)==NULL){
       printf("reopen fail\n");
    }
    int i;
    fread(&i,sizeof(int),1,fp);
    for(;i!=0;){
        char a[8];
        fseek(fp,sizeof(int)+(i-1)*sizeof(struct record),SEEK_SET);
        fread(&a[0],sizeof(a),1,fp);
        printf("%s\n",a);
        fread(&i,sizeof(unsigned),1,fp);
    }
    fclose(fp);
    return 0;
}