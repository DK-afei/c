#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 15
int a[N][4];//�洢ÿһ���и�������������λ�� 
int b[N];//ũ��ɺӵĲ���
char *name[]=
{
	"	",
		" ��",
		" ��",
		" �ײ�"
};
//�ݹ�
int search(int Step)
{
	int i;
	if(a[Step][0]+a[Step][1]+a[Step][2]+a[Step][3]==4)//�����ֲ�����ʹ��ֵ��Ϊ1�����������������ع鲽��
	{
		printf("\t���Խ�����£�\n");
		printf("����\t����\t\t\t     ״̬\n");
		printf("\t\t\t    �ϰ�\t\t����\n");
		for(i=0;i<=Step;i++)//�ܹ����������ͬ�ķ���
		{
			if(i==0)
				printf("  %d  \n",i);
			printf("          \t\t");
			if(a[i][0]==0)
				printf("�� ");
			if(a[i][1]==0)
				printf("�� ");
			if(a[i][2]==0)
				printf("�ײ� ");
			if(a[i][3]==0)
				printf("ũ�� ");
			if(a[i][0]&&a[i][1]&&a[i][2]&&a[i][3])
				printf("");
			if(a[i][0]+a[i][1]+a[i][2]+a[i][3]==3)//���������ʽ
				printf("\t");
			if(a[i][0]+a[i][1]+a[i][2]+a[i][3]==4)//���������ʽ
				printf("\t");
			printf("\t\t");
			if(a[i][0]==1)
				printf("�� ");
			if(a[i][1]==1)
				printf("�� ");
			if(a[i][2]==1)
				printf("�ײ� ");
			if(a[i][3]==1)
				printf("ũ�� ");
			if(!(a[i][0]||a[i][1]||a[i][2]||a[i][3]))
				printf(" ");
			printf("\n\n\n");
			
			if(i<Step)
			{
				printf("  %d  ",i+1);
				if(a[i][3]==0)//ũ���ڱ���
				{
					printf("	----->ũ��");
					printf("%s\n",name[b[i]+1]);
				}
				else//ũ���ڶ԰�
				{
					printf("	<-----ũ��");
					printf("%s\n",name[b[i]+1]);
				}
			}
			
		}
		printf("\n\n\n");
		return 0;
	}
	for(i=0;i<Step;i++)
	{
		if(memcmp(a[i],a[Step],16)==0)//����ǰ��������ǰ�Ĳ�����ͬ
		{
			return 0;
		}
	}
	if(a[Step][1]!=a[Step][3]&&(a[Step][2]==a[Step][1]||a[Step][0]==a[Step][1]))//�����ũ����һ����Ǻ��������Ͱײ���һ����ȡ������
	{
		return 0;
	}
	//�ݹ飬�Ӵ���һ�ֶ��￪ʼ��������ѭ����ͬʱ�޶��ݹ�Ľ���
	for(i=-1;i<=2;i++)
	{
		b[Step]=i;
		memcpy(a[Step+1],a[Step],16);//������һ��״̬��������һ���ƶ�
		a[Step+1][3]=1-a[Step+1][3];//ũ���ȥ���߻���
		if(i==-1)
		{
			search(Step+1);//���е�һ��
		}
		else
			if(a[Step][i]==a[Step][3])//��������ũ��ͬ��������
			{
				a[Step+1][i]=a[Step+1][3];//���ظ���
				search(Step+1);//������һ��
			}
	}
	return 0;
}	
int main()
{
	search(0);
	return 0;
}
