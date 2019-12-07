#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main(){
    cout<<"solution (a):"<<endl<<endl;
    int arr[3][3]={};
    cout<<"T(1)=1.----->[T(1)]b = [1 0 0]"<<endl;
    arr[0][0]=1;
    cout<<"T(x)=3x-5. ------>[T(x)]b = [-5 3 0]"<<endl;
    arr[1][0]=-5;
    arr[1][1]=3;
    cout<<"T(x^2)=9x^2-30x+25.------>[T(x^2)]b = [25 -30 9]"<<endl;
    arr[2][0]=25;
    arr[2][1]=-30;
    arr[2][2]=9;
    cout<<"      +--        --+"<<endl;
    printf("      | %2d %3d %3d |\n",arr[0][0],arr[1][0],arr[2][0]);
    printf("[T]b =| %2d %3d %3d |\n",arr[0][1],arr[1][1],arr[2][1]);
    printf("      | %2d %3d %3d |\n",arr[0][2],arr[1][2],arr[2][2]);
    cout<<"      +--        --+"<<endl<<endl<<"solution (b):"<<endl<<endl;
    cout<<"p=1+2x+3x^2"<<endl<<"basis b={1,x,x^2} so [p]b=[1 2 3]"<<endl;
    cout<<"processing [T]b X [p]b...."<<endl;
    int pb[1][3]={1,2,3},sol[1][3]={};
    sol[0][0]=arr[0][0]*pb[0][0]+arr[1][0]*pb[0][1]+arr[2][0]*pb[0][2];
    sol[0][1]=arr[0][1]*pb[0][0]+arr[1][1]*pb[0][1]+arr[2][1]*pb[0][2];
    sol[0][2]=arr[0][2]*pb[0][0]+arr[1][2]*pb[0][1]+arr[2][2]*pb[0][2];
    cout<<"printing [T(p)]b...."<<endl<<"+- -+"<<endl;
    printf("|%3d|\n",sol[0][0]);
    printf("|%3d|\n",sol[0][1]);
    printf("|%3d|\n",sol[0][2]);
    cout<<"+- -+"<<endl<<endl<<"solution (c):"<<endl<<endl;
    int solc[1][3]={};
    cout<<"by direct computation:"<<endl;
    solc[0][0]=arr[0][0]*pb[0][0]+arr[1][0]*pb[0][1]+arr[2][0]*pb[0][2];//0次向
    solc[0][1]=arr[0][1]*pb[0][0]+arr[1][1]*pb[0][1]+arr[2][1]*pb[0][2];//1次向
    solc[0][2]=arr[0][2]*pb[0][0]+arr[1][2]*pb[0][1]+arr[2][2]*pb[0][2];//2次向
    cout<<"result is :("<<sol[0][0]<<")+("<<sol[0][1]<<"x)+("<<sol[0][2]<<"x^2)"<<endl;
    system("pause");
    return 0;
}