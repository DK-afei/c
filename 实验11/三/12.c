#include <stdio.h>
#define N 12
void main()
{
	FILE*fp;
	int i,j,t=0;
	float a[N],b[N],c[N/2][2];
	if((fp=fopen("12.result.bin","w"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	for(i=0;i<N;i++)
	{
		scanf("%f",&a[i]);
	}
	for(i=0;i<N;i++)
	{
		fwrite(&a[i],sizeof(float),1,fp);
	}
	fclose(fp);
	if((fp=fopen("12.result.bin","r"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	for(i=0;i<N;i++)
	{
		fread(&b[i],sizeof(float),1,fp);
	}
	for(i=0;i<N/2;i++)
	{
		for(j=0;j<2;j++)
		{
		c[i][j]=b[t];
		t++;
		}
	}
	for(i=0;i<N/2;i++)
	{
		for(j=0;j<2;j++)
		{
	printf("%.2f ",c[i][j]);
		}
		printf("\n");
	}
}