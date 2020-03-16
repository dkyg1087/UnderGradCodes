#include<iostream>
using namespace std;
class fraction{
    public:
        int M;
        int S;
        fraction(int M,int S){
            this->M=M;
            this->S=S;
        }
        fraction operator+=(const fraction A){   
            this->M+=A.M;
            this->S+=A.S;
        }
};
int main(){
    int m,n;
    while(cin>>m>>n){
        if (m==1 && n==1) break;
        fraction L(0,1),M(1,1),R(1,0); 
        for(;;){
            double t1 = (double)m/n, t2 = (double)M.M/M.S;
            if (t1<t2){
                cout<<"L";
                R=M;
                M+=L;
            }
            else if (t1>t2){
                cout<<"R";
                L=M;
                M+=R;
            }
            else{               
                cout<<endl;
                break;
            }
        }
    }
    return 0;
}