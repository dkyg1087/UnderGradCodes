#include<iostream>
int main(){
   try{
      std::cout<<1/0;
   }
   catch (const std::exception e){
      if(e==std::DivisionByZero)
   }
}