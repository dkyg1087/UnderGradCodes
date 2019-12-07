#include<iostream>
#include <iomanip>
using namespace std;
typedef struct
{
	float coef; 
	unsigned int expon; 
}polynomial;

int main()
{
	 polynomial a[100],b[100],c[100];
	 int n,t,i,j=0,w=0;
	 for(i=0;i<100;i++)
	 {
	 	a[i].coef=b[i].coef=c[i].coef=0;
	 	a[i].expon=b[i].expon=c[i].expon=0;
	 }
	 cin >> n;
	 for(i=0;i<n;i++)
	 {
	 	cin>>a[i].coef;
	 	cin>>a[i].expon;
	 }
	 for(i=0;i<n;i++)
	 {
	 	if(i>0)
	 	{
	 		if(a[i].coef>=0)
	 		{
	 			cout<<'+';
			}
		}
	 	cout <<fixed <<setprecision(2) <<a[i].coef;
	 	if(a[i].expon==1)
	 	{cout<<'x';
		 }
		 else if(a[i].expon!=0)
	 	{
		 cout<<"x^"<< a[i].expon;
		}
	}
	 cout <<endl;
	 cin>>t;
	 for(i=0;i<t;i++)
	 {
	 	cin>>b[i].coef;
	 	cin>>b[i].expon;
	 }
	for(i=0;i<t;i++)
	 {
	 	if(i>0)
	 	{
	 		if(b[i].coef>=0)
	 		{
	 			cout<<'+';
			}
		}
	 	cout <<fixed <<setprecision(2) <<b[i].coef;
	 	if(b[i].expon==1)
	 	{cout<<'x';
		 }
		 else if(b[i].expon!=0)
	 	{
		 cout<<"x^"<< b[i].expon;
		}
	}
	cout<<endl;
	 i=0;
	 while(a[i].coef!=0&&b[j].coef!=0)
	 {
	 	if(a[i].expon > b[j].expon)
		{
			c[w].coef=a[i].coef;
			c[w].expon=a[i].expon;
			w++;
			i++;
		}
        else if (a[i].expon < b[j].expon)
		{
			c[w].coef=b[j].coef;
			c[w].expon=b[j].expon;
			w++;
			j++;
		}
        else
		{
			c[w].coef=a[i].coef +b[j].coef;
			if(c[w].coef!=0)
			{
				c[w].expon=a[i].expon;
				w++;
				
			}
			i++;
			j++;
		}
	 }
 for(i=0;i<w;i++)
	 {
	 	if(i>0)
	 	{
	 		if(c[i].coef>1)
	 		{
	 			cout<<'+';
			}
		}
			 	if(c[i].coef>1||c[i].coef<0)
	 	{
	 	cout <<fixed <<setprecision(2) <<c[i].coef;
	 	}
	 	if(c[i].expon==1)
	 	{cout<<'x';
		 }
		 else if(c[i].expon!=0)
	 	{
		 cout<<"x^"<< c[i].expon;
		}
	}
	cout<<endl;
	 return 0;
}