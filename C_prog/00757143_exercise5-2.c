#include <stdio.h>

int
main ()
{
  int i, sum, x, c;
  scanf("%d",&c);
  while(c!=0)
    {
	  scanf("%d",&x);
	  i = 1;
	  sum = 0;
	  while (i < x)
	    {
	      if (x % i == 0)
		sum = sum + i;
	      i++;
	    }
	  if (sum == x)
	    printf ("perfect\n");
          if (sum > x)
            printf ("abundant\n");
          if (sum < x)
            printf ("deficient\n");
        c--;    
    }
  return 0;

}