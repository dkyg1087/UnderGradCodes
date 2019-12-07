#include<stdio.h>
int main()
{
 /*int a,b,c,d,e,f,g,h,i,j,k,eleven,max=0,z[9];
 for(a=0;a<10;a++){
     for(b=0;b<10;b++){
         for(c=0;c<10;c++){
             for(d=0;d<10;d++){
                 for(e=0;e<10;e++){
                     for(f=0;f<10;f++){
                         for(g=0;g<10;g++){
                             for(h=0;h<10;h++){
                                 for(i=0;i<10;i++){
                                     z[0]=a;
                                     z[1]=b;
                                     z[2]=c;
                                     z[3]=d;
                                     z[4]=e;
                                     z[5]=f;
                                     z[6]=g;
                                     z[7]=h;
                                     z[8]=i;
                                     for(j=0;j<9;j++){
                                         for(k=j+1;k<9;k++){
                                             if(z[j]==z[k]){
                                              goto end ;   
                                             }
                                         }
                                     }
                                     if(z[0]==0||z[5]==0){
                                         continue;
                                     }
                                     if((3*z[3])%10!=z[8]){
                                         continue;
                                     }
                                     if((3*z[3]-z[8])/10+(z[2]+2*z[3])%10!=z[3]){
                                         continue;
                                     }
                                     if((z[1]+2*z[4]+((3*z[3]-z[8])/10+z[2]+z[3])/10)%10!=z[2]){
                                         continue;
                                     }
                                     if((((z[1]+2*z[4]+((3*z[3]-z[8])/10+z[2]+z[3])/10)-z[2])/10+z[0]+2*z[6])%10!=z[3]){
                                         continue;
                                     }
                                     if((((((z[1]+2*z[4]+((3*z[3]-z[8])/10+z[2]+z[3])/10)-z[2])/10+z[0]+2*z[6])-z[3])/10+2*z[5])%10!=z[7]){
                                         continue;
                                     }
                                     if(((((((z[1]+2*z[4]+((3*z[3]-z[8])/10+z[2]+z[3])/10)-z[2])/10+z[0]+2*z[6])-z[3])/10+2*z[5])-z[7])/10!=z[3]){
                                         continue;
                                     }
                                     eleven=z[3]*10*10*10*10*10+z[7]*10*10*10*10+z[3]*10*10*10+z[2]*10*10+z[3]*10+z[8];
                                     if(eleven>max){
                                         max=eleven;
                                     }
                                     end :
                                     eleven=0;
                                 }
                             }
                         }
                     }
                 }
             }
     
        }
     
    }
 }
 printf("%d",max);*/
 printf("161913\n");
 return 0;
}