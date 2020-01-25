#include<stdio.h>
int max_common(int a,int b)
{
   int c;
   for(c=a;(a%c)!=0||(b%c)!=0;c--);
   return c;
}
int main()
{
    int a,b;
  	printf("请输入\n");
	scanf("%d%d",&a,&b);
    printf("最大公约数%d\n",  max_common(a,b));
    return 0;
}
