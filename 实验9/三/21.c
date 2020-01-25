#include <stdio.h>
#include <string.h>
void wpos(char*string,int*begin,int*end)
{
	int i,j=0;
	int b1[100],b2[100],b3[100];
	int c=0;
	int n,max;
	printf("please intput the number of words:\n");
	scanf("%d",&n);
	for(i=0;(unsigned int)i<strlen(string);i++)
	{
		if(*(string+i)==' '||*(string+i)=='.')
		{
			*begin=i-1;
			b1[j]=*begin-c-1;
			b2[j]=c;
			b3[j]=i-1;
			j++;
			if(j==n)
				break;
			*end=i+1;
			c=*end;
		}
	}
	max=b1[0];
	for(j=0;j<n;j++)
	{
		if(max<b1[j])
		{
			max=b1[j];
			*begin=b2[j];
			*end=b3[j];
		}
	}
	printf("The longest words is %d long\n ",*end-*begin+1);
}
void main()
{
	char a[1024];
	int b=0,c=0;
	printf("The sentence is:\n");
	gets(a);
	fflush(stdin);
	wpos(a,&b,&c);
	printf("The location is:%d--%d\n",b,c);
}