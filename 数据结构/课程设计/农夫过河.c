#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 15
int a[N][4];//存储每一步中各个事物所处的位置 
int b[N];//农夫渡河的步骤
char *name[]=
{
	"	",
		" 狼",
		" 羊",
		" 白菜"
};
//递归
int search(int Step)
{
	int i;
	if(a[Step][0]+a[Step][1]+a[Step][2]+a[Step][3]==4)//若该种步骤能使各值均为1，则输出结果，进入会回归步骤
	{
		printf("\t测试结果如下：\n");
		printf("步骤\t操作\t\t\t     状态\n");
		printf("\t\t\t    南岸\t\t北岸\n");
		for(i=0;i<=Step;i++)//能够依次输出不同的方案
		{
			if(i==0)
				printf("  %d  \n",i);
			printf("          \t\t");
			if(a[i][0]==0)
				printf("狼 ");
			if(a[i][1]==0)
				printf("羊 ");
			if(a[i][2]==0)
				printf("白菜 ");
			if(a[i][3]==0)
				printf("农夫 ");
			if(a[i][0]&&a[i][1]&&a[i][2]&&a[i][3])
				printf("");
			if(a[i][0]+a[i][1]+a[i][2]+a[i][3]==3)//控制输出格式
				printf("\t");
			if(a[i][0]+a[i][1]+a[i][2]+a[i][3]==4)//控制输出格式
				printf("\t");
			printf("\t\t");
			if(a[i][0]==1)
				printf("狼 ");
			if(a[i][1]==1)
				printf("羊 ");
			if(a[i][2]==1)
				printf("白菜 ");
			if(a[i][3]==1)
				printf("农夫 ");
			if(!(a[i][0]||a[i][1]||a[i][2]||a[i][3]))
				printf(" ");
			printf("\n\n\n");
			
			if(i<Step)
			{
				printf("  %d  ",i+1);
				if(a[i][3]==0)//农夫在本岸
				{
					printf("	----->农夫");
					printf("%s\n",name[b[i]+1]);
				}
				else//农夫在对岸
				{
					printf("	<-----农夫");
					printf("%s\n",name[b[i]+1]);
				}
			}
			
		}
		printf("\n\n\n");
		return 0;
	}
	for(i=0;i<Step;i++)
	{
		if(memcmp(a[i],a[Step],16)==0)//若当前操作与以前的步骤相同
		{
			return 0;
		}
	}
	if(a[Step][1]!=a[Step][3]&&(a[Step][2]==a[Step][1]||a[Step][0]==a[Step][1]))//若羊和农夫不在一起而狼和羊或者羊和白菜在一起，则取消操作
	{
		return 0;
	}
	//递归，从带第一种动物开始依次向下循环，同时限定递归的界限
	for(i=-1;i<=2;i++)
	{
		b[Step]=i;
		memcpy(a[Step+1],a[Step],16);//复制上一步状态，进行下一步移动
		a[Step+1][3]=1-a[Step+1][3];//农夫过去或者回来
		if(i==-1)
		{
			search(Step+1);//进行第一步
		}
		else
			if(a[Step][i]==a[Step][3])//若该物与农夫同岸，带回
			{
				a[Step+1][i]=a[Step+1][3];//带回该物
				search(Step+1);//进行下一步
			}
	}
	return 0;
}	
int main()
{
	search(0);
	return 0;
}
