#include <stdio.h>
#include  <string.h>
void change (char *string)
{
	int i;
	for(i=0;(unsigned int)i<strlen(string);i++)
	{
		if(*(string+i)>='a'&&*(string+i)<='z')
		{
			*(string+i)-=32;
		}
	}
}
void main()
{
	char a[1024];
	gets(a);
	fflush(stdin);	
	change(a);
	printf("%s\n",a);

}
