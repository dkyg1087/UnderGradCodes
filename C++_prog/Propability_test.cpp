#include<iostream>
#include<time.h>
using namespace std;
int main(){
    srand(time(NULL));
    if(rand()%2==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}