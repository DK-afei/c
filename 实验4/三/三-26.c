#include<stdio.h>
void main ()
{


		int a,b,c,d;
		printf("请输入\n");
		scanf("%d%d",&a,&b);
		for(c=a;(a%c)!=0||(b%c)!=0;c--);
		printf("最大公约数%d\n",c);
		for(d=a;(d%a)!=0||(d%b)!=0;d++);
		printf("最小公倍数%d\n",d);
		

	

}