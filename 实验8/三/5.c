#include <stdio.h>

long fac(int n)
{
    if(n==0)
    return 1;
    return n*fac(n-1);
}
int main()
{
    int n;
   scanf("%d",&n);
   printf("%ld \n",fac(n));
   
   return 0;
}