#include <stdio.h>

int fibonacci(int n)
{
    if(n<3)
    return 1;
    else
    return fibonacci(n-1)+fibonacci(n-2);
    
}
int main()
{
   int n;
   scanf("%d",&n);//����������n
   printf("%d\n",fibonacci(n));
   
   return 0;
}
