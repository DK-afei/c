#include <stdio.h>
#define M 3
#define N 80
	void main()
	{
		char a[M][N];
		int i,j;
		int letters=0,digits=0,spaces=0,others=0;
		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
			scanf("%c",&a[i][j]);
			}
		}
		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
			if((a[i][j]>='a'&&a[i][j]<='z')||(a[i][j]>='A'&&a[i][j]<='Z'))
				letters++;
			else if(a[i][j]>='0'&&a[i][j]<='9')
				digits++;
			else if(a[i][j]==' ')
				spaces++;
			else
				others++;
			}
		}

		printf("字母数=%d,数字数=%d,空格数=%d,其他=%d\n",letters,digits,spaces,others);
			
	}

