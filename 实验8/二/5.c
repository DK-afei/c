#include <stdio.h>

int isOE(int number)
{
    if((number%2)==0)
    return -1;
    else 
    return 1;
}
int main()
{
   int r;
   scanf("%d",&r);
   printf("%d \n",isOE(r));
   
   return 0;
}
