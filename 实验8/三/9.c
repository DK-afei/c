#include <stdio.h>

long fun(int k)
{
    if(k>0&&k<13)
    return k*fun(k-1);
    else if(k==0)
    return 1;
    else
    printf("error");
}
int main()
{
    int n;
   scanf("%d",&n);
   printf("%ld \n",fun(n));
   
   return 0;
}
