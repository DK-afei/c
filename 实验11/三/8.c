#include<stdio.h>
#define N 4
struct part
{
	char no[10];
	int num1;
	int num2;
	int num3;
}parts[N];
void main()
{ 
	int i;
	FILE*fp;
	if((fp=fopen("C:\\Users\\Administrator\\Desktop\\新建文件夹\\3\\file.txt","r"))==NULL)
	{
		printf("Can't open the file!\n");
		return ;
	}
	for(i=0;i<N;i++)
	{
		fscanf(fp,"%s%d%d%d\n",parts[i].no,&parts[i].num1,&parts[i].num2,&parts[i].num3);
	}
	printf("零件号：	初始数量：	售出数量：	最小库存量：\n");
	for(i=0;i<N;i++)
	{
		printf(" %s		   %d		   %d		   %d\n",parts[i].no,parts[i].num1,parts[i].num2,parts[i].num3);
	}
	fclose(fp);
}