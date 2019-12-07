#include <stdio.h>

int main()
{

  int c, m, n, temp = 1;
  scanf("%d", &c);
  while (c > 0)
  {
    scanf("%d%d", &n, &m);
    while (n > 0)
    {
      temp = temp * n % m;
      n = n - 1;
    }
    printf("%d\n", temp);
    c = c - 1;
    temp = 1;
  }
  return 0;
}