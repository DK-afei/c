#include <stdio.h>

void date(int num,int*month,int*day,int*year)
{
    *year=num/10000;
    *month=(num%10000)/100;
    *day=(num%10000)%100;
}
int main()
{
   int a, b, c, d;
   scanf("%d",&a);
   date(a,&b,&c,&d);
   if(b<11)
   printf("year=%d,month=0%d,day=%d\n",d,b,c);
   
if(b>=11)
   printf("year=%d,month=%d,day=%d\n",d,b,c);
   return 0;
}
