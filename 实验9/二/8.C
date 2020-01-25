#include <stdio.h>
#include  <string.h>
int changeS (char *string)
{
		long n=0;
		int flag=1;
		if(*string=='-') 
{
			string++;flag=-1;}
		else if(*string=='+') 
			string++;
		while(*string!='\0')
		{
			n=n*10+*string-'0'; 
			string++;
		}
		return n*flag;
}
void main()
{
	char a[1024];
	gets(a);
	fflush(stdin);	
	printf("%d\n",changeS(a));

}
