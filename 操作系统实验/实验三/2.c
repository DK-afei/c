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
			printf("ȱҳ��%d\n",page[i]);
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
	printf("��ʼҳ������Ϊ:\n");
	for(i=0;i<N;i++)
		printf("%d ",page[i]);
	printf("\n");
	printf("�ڴ����Ϊ:\n");
	printf("%d\n",B);
	printf("�Ƚ��ȳ���FIFO��ҳ���û��㷨\n");
	fifo();
	printf("���㷨��ȱҳ����ȱҳ�ʷֱ��ǣ�\n");
	printf("%d,%f\n",C,(float)C/N);
	return 0;
}



