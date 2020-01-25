#include <stdio.h>
#define N 5
struct stuff
{
	int num;
	char name[20] ;
	float sr;
	float t;
}stuffs[N];
void main()
{
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%d",&stuffs[i].num);
		scanf("%s",&stuffs[i].name);
		scanf("%f",&stuffs[i].sr);
		scanf("%f",&stuffs[i].t);
	}
	printf("识别号：\t姓名：\t\t工资率：\t已经工作时间：\n");
	for(i=0;i<N;i++)
	{
		printf("%d\t\t",stuffs[i].num);
		printf("%s\t\t",stuffs[i].name);
		printf("%f\t",stuffs[i].sr);
		printf("%f\n",stuffs[i].t);
	}
	printf("\n");
}