#include<stdio.h>
int min_common(int a,int b)
{
   int d;
   for(d=a;(d%a)!=0||(d%b)!=0;d++);
   return d;
}
int main()
{
    int a,b;
  	printf("请输入\n");
	scanf("%d%d",&a,&b);
    printf("最小公倍数%d\n",  min_common(a,b));
    return 0;
}