#include<iostream>
#include<stdlib.h>
using namespace std;
class Vector{
    public:
        double x,y;
        void Set(double,double);
};
class myclass{
    public:
        int Mul(int,int);
        double Mul(double,double);
        int Mul(int,int,int);
        double Mul(double,double,double);
        Vector Mul(Vector,Vector);
};
int myclass::Mul(int a,int b){
    return a*b;
}
double myclass::Mul(double a,double b){
    return a*b;
}
int myclass::Mul(int a,int b,int c){
    return a*b*c;
}
double myclass::Mul(double a,double b,double c){
    return a*b*c;
}
Vector myclass::Mul(Vector a,Vector b){
    Vector tempVec;
    tempVec.x=a.x*b.x;
    tempVec.y=a.y*b.y;
    return tempVec;
}
void Vector::Set(double a,double b){
    x=a;
    y=b;
    return;
}
int main(){
    myclass X;
    Vector i;
    i.Set(20.2,40);
    Vector j;
    j.Set(15,45.7);
    cout<<"Vector i=("<<i.x<<","<<i.y<<")"<<endl;
    cout<<"Vector j=("<<j.x<<","<<j.y<<")"<<endl;
    Vector k;
    k=X.Mul(i,j);
    cout<<"Vector k=("<<k.x<<","<<k.y<<")"<<endl;
    return 0;
}