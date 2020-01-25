#include <stdio.h>

double power(double n,int p)
{
    if(p==0)
    return 1.0;
     else if(p>0)
     return n*power(n,p-1);
    else
    return power(n,p+1)/n;
}
int main()
{
    int p;
    double n;
   scanf("%lf%d",&n,&p);
   printf("%lf \n",power(n,p));
   
   return 0;
}