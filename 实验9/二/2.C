#include <stdio.h>
#include  <string.h>
int count(char *string)
{
	int i;
	int a=0;
	for(i=0;(unsigned int)i<strlen(string);i++)
	{
		if(*(string+i)>='a'&&*(string+i)<='z'||*(string+i)>='A'&&*(string+i)<='Z')
		{
		a++;
		}
	}
	return a;
}
void main()
{
	char a[1024];
	gets(a);
	fflush(stdin);	
	printf("%d\n",count(a));

}

     
