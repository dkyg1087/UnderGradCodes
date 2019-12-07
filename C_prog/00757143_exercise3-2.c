#include <stdio.h>

int main()
{

    long int x, y, s = 0, temp;

    while (scanf("%ld%ld", &x, &y) != EOF)
    {
        temp = x + y;
        while (temp != 0)
        {
            s = s + temp % 10;
            temp = temp / 10;
        }
        printf("%ld\n", s);
        s = 0;
    }
    return 0;
}