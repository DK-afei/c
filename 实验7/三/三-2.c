#include<stdio.h>
#define n 100
int main()
{
		char s[100],*p ,*q ,del_x;
		printf("输入小于%d个字符:",n);
		gets(s);
		printf("输入要删除的字符:");
		scanf("%c",&del_x);
		for(p=s,q=s;*p!='\0';p++)
		 if(*p!=del_x)
		*q++=*p;
		*q=*p;
		puts(s);
		return 0;
}