#include<stdio.h>
#define n 100
int main()
{
		char s[100],*p ,*q ,del_x;
		printf("����С��%d���ַ�:",n);
		gets(s);
		printf("����Ҫɾ�����ַ�:");
		scanf("%c",&del_x);
		for(p=s,q=s;*p!='\0';p++)
		 if(*p!=del_x)
		*q++=*p;
		*q=*p;
		puts(s);
		return 0;
}