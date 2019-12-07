#include <stdio.h>
int main()
{
int a[1000];
while(scanf("%d",&a[0])==1){
int max_len=1,i=0,n=1,j,k,max,min;
while(scanf(",%d",&a[n])==1){
      n++;
}
for(i = 0; i < n; ++i) {
    for(j = i+1; j < n; ++j) {
            if (a[i]>a[j]) {
                  max = a[i]; 
                  min = a[j];
            } 
            else {
                  max = a[j]; 
                  min = a[i];
            }
            for(k=i+1; k < j; ++k) {
                   if (a[k]<min || a[k]>max) {
                          break;
                   }
            }
            if (k== j) { 
                  // the subsequence between i and j is a bounded subsequence.
                  // the length of this bounded subseqnece is j-i+1
                  int len = j-i+1;
                  if (len > max_len) {
                         max_len = len;     
                  }
            }  
      }
}
printf("%d\n",max_len);
}
return 0;
}