#include<stdio.h>
int main()
{
			char s[100],*p ,*q ;
			puts("输入小于100个字符:");
			gets(s);
			char del_x;
			printf("输入要删除的字符:");
			scanf("%c",&del_x);
			for(p=s,q=s;*p!='\0';p++)
			 if(*p!=del_x)*q++=*p;
			*q=*p;
			puts(s);
			return 0;
}
