#include<stdio.h>
void main ()
{


		int a,b,c,d;
		printf("������\n");
		scanf("%d%d",&a,&b);
		for(c=a;(a%c)!=0||(b%c)!=0;c--);
		printf("���Լ��%d\n",c);
		for(d=a;(d%a)!=0||(d%b)!=0;d++);
		printf("��С������%d\n",d);
		

	

}