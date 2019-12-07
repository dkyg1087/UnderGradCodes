#include<stdio.h>

int main()
{
float weight,height,BMI;
scanf ("%f",&weight);
scanf ("%f",&height);
BMI = weight/height/height;
printf ("%.2f\n",BMI );
return 0;
}
