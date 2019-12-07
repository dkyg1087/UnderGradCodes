#include <stdio.h>

int
main ()
{
  int i, j, N;

  while (scanf ("%d", &N) != EOF)
    {
      for (i = 1; i <= N; i++)
	{
	  for (j = 1; j <= N; j++)
	    {
	      if (i == 1 || i == N || j == 1 || j == N)
		{
		  printf ("A");
		}
	      else
		{
		  printf ("B");
		}
	    }
	  printf ("\n");
	}
    }

  return 0;
}
