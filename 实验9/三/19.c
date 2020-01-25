#include <stdio.h>
#include <string.h>
void svowel(char*s1,char*s2)
{
    int i;
	int j=0;
    for(i=0;(unsigned int)i<strlen(s1)+1;i++)
	{
		if(*(s1+i)=='a'||*(s1+i)=='e'||*(s1+i)=='i'||*(s1+i)=='o'||*(s1+i)=='u'||*(s1+i)=='A'||*(s1+i)=='E'||*(s1+i)=='I'||*(s1+i)=='O'||*(s1+i)=='U'||*(s1+i)=='\0')
		{	
			*(s2+j)=*(s1+i);
		    j++;
		}
	}
}

int main()
{
    char a[1024],b[1024];
    gets(a);
    svowel(a,b);
    puts(b);
	printf("\n");
    return 0;
}
