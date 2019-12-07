#include <stdio.h>

int
main ()
{
  int n, i, sum, x, y;
  while (scanf ("%d%d", &x,&y) != EOF)
    {
      for (n = x; n <= y; n++)
	{
	  i = 1;
	  sum = 0;
	  while (i < n)
	    {
	      if (n % i == 0)
		sum = sum + i;
	      i++;
	    }
	  if (sum == n)
	    printf ("%d\n", n);
	}
    }
  return 0;

}