#include<stdio.h>
#include<stdlib.h>
#define B 3
#define N 12
typedef struct flag
{
	int blocks[B];
	int index;
}FLAG;
int page[N]={1,2,3,4,1,2,5,1,2,3,4,5};
int block[B]={0};
int C;
FLAG bflag={{0,0,0},-1};
void disPlay()
{
	int i;
	for(i=0;i<B;i++)
	{
		printf("%d\t",block[i]);
	}
	printf("\n");
}
int inBlcok(int value)
{
	int index=-1;
	int i;
	for(i=0;i<B;i++)
	{
		if(block[i]==value)
		{
			index=i;
			break;
		}
	}
	return index;
}
int checkFlag()
{
	int i=0;
	int index=-1;
	while(i<B)
	{
		if(bflag.blocks[i]==1)
		{
			bflag.blocks[i]=0;
			index=i;
			break;
		}
		i++;
	}
	return index;
}
void fifo()
{
	int i=0;
	int getIndex;
	int getflag;
	while(i<N)
	{
		getIndex=inBlcok(page[i]);
		if(getIndex==-1)
		{
			printf("缺页：%d\n",page[i]);
			C++;
			if((getflag=checkFlag())!=-1)
			{
				block[getflag]=page[i];
			}
			else
			{
				block[i%B]=page[i];
			}
		}
		disPlay();
		i++;
	}
}




int main()
{
	int i;
	printf("初始页面序列为:\n");
	for(i=0;i<N;i++)
		printf("%d ",page[i]);
	printf("\n");
	printf("内存块数为:\n");
	printf("%d\n",B);
	printf("先进先出（FIFO）页面置换算法\n");
	fifo();
	printf("该算法的缺页数和缺页率分别是：\n");
	printf("%d,%f\n",C,(float)C/N);
	return 0;
}



