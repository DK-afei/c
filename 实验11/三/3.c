#include <stdio.h> 
#define N 10
struct person
{
	char name[20];
	char num[20];
}pers[N];
void main()
{
	int i;
	FILE*fp;
	if((fp=fopen("file.txt","w"))==NULL)
	{
		printf("Can't open the file!");
		return;
	}
	for(i=0;i<N;i++)
	{
		scanf("%s%s",pers[i].name,pers[i].num);
	}
		for(i=0;i<N;i++)
	{
	fprintf(fp,"%s%s",pers[i].name,pers[i].num);
	fprintf(fp,"\n");
	}
	fclose (fp);
}