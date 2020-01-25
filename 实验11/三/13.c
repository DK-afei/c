#include <stdio.h>
void main()
{
	FILE*fp;
	float a[5][4],b[5][4],ave[4],sum;
	int i,j;
	if((fp=fopen("grades.bin","w"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%f",&a[i][j]);
		}
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<4;j++)
		{
			fwrite(&a[i][j],sizeof(float),1,fp);
		}
	}
	fclose(fp);
	if((fp=fopen("grades.bin","r"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
		for(i=0;i<5;i++)
	{
			sum=0;
		for(j=0;j<4;j++)
		{
			fread(&b[i][j],sizeof(float),1,fp);
			sum+=b[i][j];
		}
		ave[i]=sum/4;
	}
		for(i=0;i<4;i++)
		{
			printf("%f",ave[i]);
		}
}