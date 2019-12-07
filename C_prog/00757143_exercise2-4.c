#include <stdio.h>  
  
int main()  
{  
 int c,hr=0,min=0,sec=0;
 char n;
 scanf("%d",&c);  
 while(c>0){  
     scanf("%2d%1c%2d%1c%2d",&hr,&n,&min,&n,&sec);  
     if(hr > 12){  
         hr=hr-12;  
         printf("%02d:%02d:%02d p.m.\n",hr,min,sec);  
     }  
     else if(hr==12){  
         printf("%02d:%02d:%02d p.m.\n",hr,min,sec);  
     }   
     else if (hr==0){  
         printf("12:%02d:%02d a.m.\n",min,sec);  
     }  
     else{  
         printf("%02d:%02d:%02d a.m.\n",hr,min,sec);  
     }  
     c=c-1;  
       
 }  
    return 0;  
}  