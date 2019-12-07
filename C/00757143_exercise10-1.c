#include<stdio.h>
main() {
	int a[40],b,c,d;
	a[0]=1;
	a[1]=2;
	for(b=2;b<40;b++)
		a[b]=a[b-1]+a[b-2];
	scanf("%d", &d);
	for(;d>0;d--){
		scanf("%d", &c);
		printf("%d = ",c);
		int e=0;
		for(b=39;b>=0;b--){
			if(c/a[b]==1){
				printf("1");
				c=c%a[b];
				e=1;
			}
			else if(e)
				printf("0");
		}
		printf(" (fib)\n");
	}
	return 0;
}