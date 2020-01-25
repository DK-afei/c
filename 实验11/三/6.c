#include <stdio.h>
#define N 5
struct emloy
{
	char name[10];
	char place[5];
	int num;
	float rate;
	char date[10];
}emloys[N];
void main()
{ 
	int i;
	FILE*fp;
	if((fp=fopen("C:\\Users\\Administrator\\Desktop\\新建文件夹\\3\\emloy.txt","r"))==NULL)
	{
		printf("Can't open the file!\n");
		return ;
	}
	for(i=0;i<N;i++)
	{
		fscanf(fp,"%s%s%d%f%s\n",emloys[i].name,emloys[i].place,&emloys[i].num,&emloys[i].rate,emloys[i].date);
	}
	for(i=0;i<N;i++)
	{
		printf("%s	%s %d %f %s\n",emloys[i].name,emloys[i].place,emloys[i].num,emloys[i].rate,emloys[i].date);
	}
	fclose(fp);
}