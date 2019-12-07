#include<iostream>
#include<cmath>
using namespace std;
class Int{
	public:
	int num;
	int operator+();
};
int Int::operator+(){
	this->num=this->num+1;
	return this->num;
}
int main(){
	Int i;
	int g;
	i.num=0;
	cout<<i.num;
	enum a{A,B,C,D,E,F}
	a=D;
	cout<<a;
}