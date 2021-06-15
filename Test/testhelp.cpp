#include<iostream>
using namespace std;
int primes[9]={2,3,5,7,11,13,17,19,23};
int prime_01[9]={0,0,0,0,0,0,0,0,0};
int counter = 0;
int flag=0;
int k=9;
int one_counter = 0;
int check(int i, int number){//確認是否能用該質數進行拆解 
    if(primes[i]>number || prime_01[i]==1){
        return 0;
    }
    return 1;
}
void ana_pri(int number) {
    cout<<"number:"<<number<<" called"<<endl;
    if(number==1){
        one_counter++;
    }
    int i,j;
    while(number>=2){//大於最小質數
        cout<<"current number "<<number<<endl;
        for(i=k-1;i>=0;i--){//從當前陣列primes中最大的質數開始確認 
            if(check(i,number)==1){
                prime_01[i]=1;//用primes[i]拆解number 
                cout<<number<<","<<primes[i]<<endl;//
                counter++;
                if(number-primes[i]==0){
                    flag=1;
                    return;
                }
                ana_pri(number-primes[i]);
                if(flag==1) return;
                prime_01[i]=0;
                cout<<"at number "<<number<<" making prime "<<primes[i]<<" available again"<<endl<<"current prime_01 is:"<<endl;;
                for(int i=0;i<k;i++){
                    cout<<prime_01[i]<<" ";
                }
                cout<<endl;
                counter--;
                if(one_counter==10)exit(0);
            }
        }
    }
    cout<<"return from number:"<<number<<endl<<endl;
}
int main(){
    ana_pri(29);
}