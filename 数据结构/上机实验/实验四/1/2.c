#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define m 30
void reverse(char a[])
{
	unsigned int i;
	char b[m]="";
	for(i=0;i<strlen(a);i++)
	{
		b[i]=a[strlen(a)-i-1];
	}
	puts(b);
}
int main()
{
	char a[m];
	gets(a);
	reverse(a);
	return 0;
}