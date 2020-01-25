#include <stdio.h>
#include <math.h>

double carea(double r)
{
    scanf("%lf",&r);
    return 3.14*r*r;
}
int main()
{
   double r;
   printf("s=%.2lf \n",carea(r));
   
   return 0;
}
