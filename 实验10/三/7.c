#include <stdio.h>
#define N 3
struct stuff
{
	int num;
	char name[20] ;
	float sr;
	float t;
}stuffs[N];
void main()
{
	struct stuff t;
	int i,j;
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
	for(i=0;i<N-i-1;i++)
	{
		for(j=0;j<N-1;j++)
		{
			if(stuffs[j].sr>stuffs[j+1].sr)
			{
				t=stuffs[j];
				stuffs[j]=stuffs[j+1];
				stuffs[j+1]=t;
			}
		}
	}
	printf("排序后的表:\n");
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