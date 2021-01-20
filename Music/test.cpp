#include <cstdio>
#include <windows.h>
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

int main()
{
    int pai = 600, ban = 300;
    int ting = 50;

    Sleep(1000);
    Beep(do1, pai);
    Sleep(ting);
    Beep(la, ban);
    Beep(sla, ban);
    Sleep(ting);
    Beep(do1, pai * 0.75);
    Beep(re1, pai * 0.25);
    Sleep(ting);
    Beep(do1, pai);
    Sleep(ting);

    Beep(fa, pai * 0.5);
    Beep(mi, pai * 0.5);
    Sleep(ting);
    Beep(fa, pai * 0.5);
    Beep(so, pai * 0.5);
    Sleep(ting);
    Beep(la, pai * 2);
    Sleep(ting);

    Beep(do1, pai);
    Sleep(ting);
    Beep(fa, pai * 0.5);
    Beep(so, pai * 0.5);
    Sleep(ting);
    Beep(la, pai * 0.75);
    Beep(sla, pai * 0.25);
    Sleep(ting);
    Beep(la, pai);
    Sleep(ting);

    Beep(sla, pai * 0.5);
    Beep(sla, pai * 0.5);
    Sleep(ting);
    Sleep(ban);
    Beep(la, ban);
    Sleep(ting);
    Beep(so, pai * 2);
    Sleep(ting);

    Beep(do, pai * 0.5);
    Beep(fa, pai * 0.5);
    Sleep(ting);
    Beep(fa, pai * 0.5);
    Beep(mi, pai * 0.5);
    Sleep(ting);
    Beep(fa, pai * 0.75);
    Beep(so, pai * 0.25);
    Sleep(ting);
    Beep(la, pai * 0.5);
    Sleep(ban);
    Sleep(ting);

    Beep(fa, pai * 0.5);
    Beep(sla, pai * 0.5);
    Sleep(ting);
    Beep(sla, pai * 0.5);
    Beep(la, pai * 0.5);
    Sleep(ting);
    Beep(sla, pai * 0.75);
    Beep(do1, pai * 0.25);
    Sleep(ting);
    Beep(re1, pai * 0.5);
    Sleep(pai * 0.5);
    Sleep(ting);

    Beep(do1, pai * 0.5);
    Beep(fa, pai * 0.5);
    Sleep(ting);
    Beep(do1, pai * 0.5);
    Beep(sla, pai * 0.5);
    Sleep(ting);
    Beep(la, pai);
    Sleep(ting);
    Beep(so, pai);
    Beep(fa, pai * 3);
    Sleep(ting);
    Sleep(pai);
    Sleep(ting);

    Beep(fa, pai);
    Sleep(ting);
    Beep(mi, pai * 0.5);
    Beep(mi, pai * 0.5);
    Sleep(ting);
    Beep(fa, pai);
    Sleep(ting);
    Beep(do, pai * 0.5);
    Sleep(ban);
    Sleep(ting);

    Beep(fa, ban);
    Beep(mi, ban);
    Sleep(ting);
    Beep(fa, ban);
    Beep(so, ban);
    Sleep(ting);
    Beep(la, ban);
    Beep(la, ban);
    Sleep(ting);
    Beep(la, ban);
    Sleep(ban);
    Sleep(ting);

    Beep(do1, pai);
    Sleep(ting);
    Beep(do1, ban);
    Beep(do1, ban);
    Sleep(ting);
    Beep(sla, pai);
    Sleep(ting);
    Beep(la, ban);
    Sleep(ban);
    Sleep(ting);

    Beep(do1, ban);
    Beep(re1, ban);
    Sleep(ting);
    Beep(mi1, ban);
    Beep(re1, ban);
    Sleep(ting);
    Beep(do1, pai);
    Beep(so, pai);
    Sleep(ting);

    Beep(do1, pai * 3);
    Sleep(ting);
    Sleep(pai);
    Sleep(ting);

    Beep(do1, pai);
    Sleep(ting);
    Beep(la, ban);
    Beep(sla, ban);
    Sleep(ting);
    Beep(do1, pai * 0.75);
    Beep(re1, pai * 0.25);
    Sleep(ting);
    Beep(do1, pai);
    Sleep(ting);

    Beep(fa, ban);
    Beep(mi, ban);
    Sleep(ting);
    Beep(fa, ban);
    Beep(so, ban);
    Sleep(ting);
    Beep(la, pai * 2);
    Sleep(ting);

    Beep(do1, pai);
    Sleep(ting);
    Beep(fa, ban);
    Beep(so, ban);
    Sleep(ting);
    Beep(la, pai * 0.75);
    Beep(sla, pai * 0.25);
    Sleep(ting);
    Beep(la, pai);
    Sleep(ting);

    Beep(sla, ban);
    Beep(sla, ban);
    Sleep(ting);
    Sleep(ban);
    Beep(la, ban);
    Sleep(ting);
    Beep(so, pai * 2);
    Sleep(ting);

    Beep(fa, ban);
    Beep(mi, ban);
    Sleep(ting);
    Beep(fa, ban);
    Beep(so, ban);
    Sleep(ting);
    Beep(la, ban);
    Beep(la, ban);
    Sleep(ting);
    Beep(la, ban);
    Sleep(ban);
    Sleep(ting);

    Beep(do1, ban);
    Beep(fa, ban);
    Sleep(ting);
    Beep(do1, ban);
    Beep(sla, ban);
    Sleep(ting);
    Beep(la, pai);
    Sleep(ting);
    Beep(so, pai);
    Sleep(ting);

    Beep(fa, pai * 3);
}