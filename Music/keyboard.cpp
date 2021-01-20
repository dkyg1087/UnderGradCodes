#include <cstdio>
#include <windows.h>
#include<conio.h>
#define qdo 262
#define qre 294
#define qmi 330 //q字首為低音，1字尾為高音，s字首為半音階
#define qfa 349
#define qso 392
#define qla 440
#define qsi 494
#define do 523
#define re 578
#define mi 659
#define fa 698
#define so 784
#define la 880
#define si 988
#define do1 1046
#define re1 1175
#define mi1 1318
#define fa1 1480
#define so1 1568
#define la1 1760
#define si1 1976
#define sqdo 277
#define sqre 311
#define sqfa 370
#define sqso 415
#define sqla 466
#define sdo 554
#define sre 622
#define sfa 740
#define sso 831
#define sla 932
#define sdo1 1046
#define sre1 1245
#define sfa1 1480
#define sso1 1661
#define sla1 1865

int main(){
    char c;
    while(true){
        c = getche();
        if(c=='q')break;
        if(c=='a')Beep(do,300);
        if(c=='w')Beep(sdo,300);
        if(c=='s')Beep(re,300);
        if(c=='e')Beep(sre,300);
        if(c=='d')Beep(mi,300);
        if(c=='f')Beep(fa,300);
        if(c=='t')Beep(sfa,300);
        if(c=='g')Beep(so,300);
        if(c=='y')Beep(sso,300);
        if(c=='h')Beep(la,300);
        if(c=='u')Beep(sla,300);
        if(c=='j')Beep(si,300);
        if(c=='k')Beep(do1,300);
        if(c=='o')Beep(sdo1,300);
        if(c=='l')Beep(re1,300);
    }
}