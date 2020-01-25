#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000
void main()
{
	FILE*fp;
	int i,j,b[N];
	if((fp=fopen("file.txt","w+"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	srand(time(NULL));
	for(i=0;i<N;i++)
	{
		fprintf(fp,"%d	",rand()%9000+1000);
	}
	rewind(fp);
	for(i=0;i<N;i++)
	{
		fscanf(fp,"%d	",&b[i]);
	}
		for(i=0,j=0;i<N;i++)
	{
		if((b[i]%10)==(b[i]%10000/1000))
		{
			j++;
		}
	}
		printf("%d\n",j);
		for(i=0;i<N;i++)
	{
		if(b[i]%2==0)
		{
			b[i]*=10;
		}
	}
	rewind(fp);
	for(i=0;i<N;i++)
	{
		fprintf(fp,"%d	",b[i]);
	}
	fclose(fp);
}