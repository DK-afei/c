#include <stdio.h>
#define N 100
int init(int a[])
{
	int n;
	int i;
	printf("����������Ԫ�ص���Ŀ��\n");
	scanf("%d",&n);
	printf("�����������Ԫ�أ�\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	return n;
}
void xiabiao(int a[],int n)
{
	int j;
	for(j=0;j<n;j++)
		printf("%d ",a[j]);
	printf("\n");
}
void zhizhen(int *p,int n)
{
	int j;
	for(j=0;j<n;j++)
		printf("%d ",*(p+j));
	printf("\n");
}
void oushu(int *p,int n)
{
	int sum=0;
	int j;
	for(j=0;j<n;j++)
	{
		if(*(p+j)%2==0)
			sum+=*(p+j);
	}
	printf("��������ż����ͽ���ǣ�%d\n",sum);
}
void kuodak(int *p,int n)
{
	int j;
	int k;
	printf("������Ҫ����ı�����\n");
	scanf("%d",&k);
	for(j=0;j<n;j++)
	{
		*(p+j)=(*(p+j)*k);
	}
}
void oushuweizhi(int *p,int n)
{
	int sum=0;
	int j;
	for(j=0;j<n;j++)
	{
		if(j%2==0)
			sum+=*(p+j);
	}
	printf("��������ż��λ����ͽ���ǣ�%d\n",sum);
}
void max(int *p, int n)
{
	int max=*p;
	int j;
	for(j=0;j<n;j++)
	{
		if(*(p+j)>max)
			max=*(p+j);
	}
	printf("��������Ԫ�����ǣ�%d\n",max);
}
void min(int *p, int n)
{
	int min=*p;
	int j;
	for(j=0;j<n;j++)
	{
		if(*(p+j)<min)
			min=*(p+j);
	}
	printf("������С��Ԫ�����ǣ�%d\n",min);
}
void look(int *p, int n)
{
	int z;
	int j;
	printf("������Ҫ���ҵ�Ԫ�أ�\n");
	scanf("%d",&z);
	for(j=0;j<n;j++)
	{
		if(z==*(p+j))
		{
			printf("���ҳɹ���%d\n",z);
			break;
		}

	}
	if(j==n)
		printf("����ʧ�ܣ�%d\n",z);
}
int main()
{
	int a[N];
	int num;
	num=init(a);
	xiabiao(a,num);
	zhizhen(a,num);
	oushu(a,num);
	kuodak(a,num);
	zhizhen(a,num);
	oushuweizhi(a,num);
	max(a,num);
	min(a,num);
	look(a,num);
	return 0;
}