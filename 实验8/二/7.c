#include <stdio.h>

void sa(int x1,int x2,int*sum,int*mul)
{
    *sum=x1+x2;
    *mul=x1*x2;
}
int main()
{
   int a,b,sum,mul;
   scanf("%d%d",&a,&b);
   sa(a,b,&sum,&mul);
   printf("sum=%d,mul=%d\n",sum,mul);
   
   return 0;
}