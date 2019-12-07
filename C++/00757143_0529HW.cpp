#include<iostream>
using namespace std;

class Timer{
    private:
        unsigned int min,sec;
    public: 
        Timer():min(0),sec(0){}
        friend ostream& operator<<(ostream&,Timer);
        friend Timer operator+(int,Timer);
        void check(Timer*);
        Timer operator+(const int);
        Timer operator--(int);
        Timer operator++();
        Timer operator=(const Timer);
        Timer operator=(const int);
};
void Timer::check(Timer* T){
    if(T->sec>=60){
        T->min+=(T->sec/60);
        T->sec=T->sec%60;
    }
    if(T->min>=10){
        sec+=min*60;
        min=0;
        sec-=600;
        check(this);
    }
    return;
}
Timer Timer::operator=(const Timer T){
    this->min=T.min;
    this->sec=T.sec;
    check(this);
}
Timer Timer::operator=(const int a){
    this->sec=a;
    this->min=0;
    check(this);
}
Timer Timer::operator++(){
    this->sec++;
    check(this);
    return *this;
}
Timer Timer::operator--(int){
    Timer temp=*this;
    if(this->sec==0){
        this->sec=59;
        this->min--;
    }
    else sec--;
    return temp;
}
Timer Timer::operator+(const int a){
    this->sec+=a;
    check(this);
    return *this;
}
ostream& operator<<(ostream& out,Timer a){
    out <<a.min<<" min "<<a.sec<<" sec"<<endl;//編碼怪怪的不能印中文 QQ
    return out;
}
Timer operator+(int a,Timer b){
    b.sec=b.sec+a;
    b.check(&b);
    return b;
}
int main() {
    Timer foo ; //內定為0分0秒
    foo = foo + 100 ; //加上100秒
    cout<< foo << endl; //顯示現在分秒數：1分40秒
    foo = 700 + foo ;
    cout<< foo << endl; //顯示現在分秒數：3分20秒
    cout<< ++foo << endl; //顯示現在分秒數：3分21秒
    foo = 10 ; //重新設定為10秒鐘
    for (int i= 0 ; i<= 10 ; ++i){
       cout<< foo--<< endl; 
    } //倒數計時列印時刻
    return 0 ;
    }