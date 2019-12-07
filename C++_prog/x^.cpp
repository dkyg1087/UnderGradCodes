#include <iostream>

using namespace std;


int main() 
{
 signed int a;
 int n, t;
 
 while(cin>>a)
 {
  n = 8;
  t = 0;
 while(n > 0)
 { 
 
  if (a > 1 || a < -1)
  {  
   if (t != 0)
   {
   if (n > 1)
   {
    if(a > 0)
    cout<< " + " << a << "x^" << n;
    else cout<< " - " << -a << "x^" << n;
   }
   else
   {
    if (a > 0) cout<< " + " << a << 'x';
    else cout<< " - " << -a << 'x';
    
   }
   t++;
   }
  
   if (t == 0)
   {
    if (n > 1)
    cout<< a << "x^" << n;
    else cout<< a << 'x';
    t++;
   }
   
  }
  
  else if (a == 1 || a == -1)
  {  
   if (t != 0)
   {
   if (n > 1)
   {
    if(a > 0)
    cout<< " + " << "x^" << n;
    else cout<< " - " << "x^" << n;
   }
   else
   {
    if (a > 0) cout<< " + " << 'x';
    else cout<< " - " << 'x';
    
   }
   t++;
   }
  
   if (t == 0)
   {
    if (a > 0){
    if (n > 1)
    cout<< "x^" << n;
    else cout<< 'x';
    t++;}
    else {
     if (n > 1)
    cout<< "-x^" << n;
    else cout<< "-x";
    t++;
    }
   }
   
  }
  cin>>a;
  n--;
 }

 if (t != 0)
 {
 if(a > 0)
 cout<< " + " << a << endl;
 else if (a == 0)
 cout<< endl;
 else cout<< " - " << -a << endl;
 }
 else cout<< a << endl;
}
 return 0;
}