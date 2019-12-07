#include<iostream>
using namespace std;
char canvas[52][52];
int M,N;//j管M,X(橫的),i管N,Y(直的)
void I(){
    int i,j;
    cin>>M>>N;
    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++){
            canvas[i][j]='O';
        }
    }
    for(i=0;i<=N+1;i++){
        canvas[i][0]='#';
        canvas[i][M+1]='#';
    }
    for(j=0;j<=M+1;j++){
        canvas[0][j]='#';
        canvas[N+1][j]='#';
    }
    getchar();
    return;
}
void C(){
    int i,j;
    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++){
            canvas[i][j]='O';
        }
    }
    getchar();
    return;
}
void L(){
    int x,y;
    char c;
    cin>>x>>y>>c;
    canvas[y][x]=c;
    getchar();
    return;
}
void V(){
    int x,y1,y2,i;
    char c;
    cin>>x>>y1>>y2>>c;
    if(y1>y2){
        int temp;
        temp=y1;
        y1=y2;
        y2=temp;
    }
    for(i=y1;i<=y2;i++){
        canvas[i][x]=c;
    }
    getchar();
    return;
}
void H(){
    int x1,x2,y,i;
    char c;
    cin>>x1>>x2>>y>>c;
    if(x1>x2){
        int temp;
        temp=x1;
        x1=x2;
        x2=temp;
    }
    for(i=x1;i<=x2;i++){
        canvas[y][i]=c;
    }
    getchar();
    return;
}
void K(){
    int x1,x2,y1,y2,i,j;
    char c;
    cin>>x1>>y1>>x2>>y2>>c;
     if(y1>y2){
        int temp;
        temp=y1;
        y1=y2;
        y2=temp;
    }
    if(x1>x2){
        int temp;
        temp=x1;
        x1=x2;
        x2=temp;
    }
    for(j=x1;j<=x2;j++){
        for(i=y1;i<=y2;i++){
            canvas[i][j]=c;
        }
    }
    getchar();
    return;
}
void S(){
    string s;
    cin>>s;
    cout<<s<<endl;
    int i,j;
    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++){
            cout<<canvas[i][j];
        }
        cout<<endl;
    }
    getchar();
    return;
}
void F(int x,int y,char c,char cen){
    if(cen==c)return;
    canvas[y][x]=c;
    if(canvas[y+1][x]==cen)F(x,y+1,c,cen);
    if(canvas[y-1][x]==cen)F(x,y-1,c,cen);
    if(canvas[y][x+1]==cen)F(x+1,y,c,cen);
    if(canvas[y][x-1]==cen)F(x-1,y,c,cen);
    return;
}
int main(){
    char command;
    for(;;){
        cin>>command;
        if(command=='X')break;
        switch (command)
        {
        case 'I':
            I();
            break;
        case 'C':
            C();
            break;
        case 'L':
            L();
            break;
        case 'V':
            V();
            break;
        case 'H':
            H();
            break;
        case 'K':
            K();
            break;
        case 'S':
            S();
            break;
        case 'F':
            int x,y;
            char c;
            cin>>x>>y>>c;
            F(x,y,c,canvas[y][x]);
            getchar();
            break;
        default:
            char junk;
            junk=getchar();
            for(;junk!='\n';)junk=getchar();
        }
    }
    return 0;
}