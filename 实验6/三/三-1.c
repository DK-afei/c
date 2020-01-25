#include <stdio.h>
#include <string.h>
#define N 1024
void main ()
{
	char a[N];
	int  b[26][2];
	int i, j, t;
	for(i=0;i<(int)strlen(a);i++)
	{
		b[i][0]='a'+i;
		b[i][1]=0;
	}
	gets(a);
	for(i=0;i<26;i++)
	{
		if(a[i]>='a'&&a[i]<='z')
			b[a[i]-'a'][1]++;
	}
	for(i=0;i<26-1;i++)
	{
		{
			for(j=0;j<26-i-1;j++)
			{
				if(b[j][1]<b[j+1][1])
				{
					t=b[j+1][1];
					b[j+1][1]=b[j][1];
					b[j][1]=t;

					t=b[j][0];
					b[j][0]=b[j+1][0];
					b[j+1][0]=t;
				}
			}
		}
	}
	for(i=0;b[i][1]>0;i++)
	{
		printf("%c\t%d\n",b[i][0],b[i][1]);
	}
	printf("\n");
}