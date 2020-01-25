#include <stdio.h>
#define M 2
#define N 1024
void main()
{
	FILE*fp;
	char a[M][N];
	int i;
	if((fp=fopen("text.txt","w"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	for(i=0;i<M;i++)
	gets(a[i]);
	for(i=0;i<M;i++)
	{
		fputs(a[i],fp);
		fprintf(fp,"\n");
	}
	fclose(fp);
}