#include <stdio.h>
#define N 100
int init(int a[])
{
	int n;
	int i;
	printf("请输入数组元素的数目：\n");
	scanf("%d",&n);
	printf("请输入数组的元素：\n");
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
	printf("数组所有偶数求和结果是：%d\n",sum);
}
void kuodak(int *p,int n)
{
	int j;
	int k;
	printf("请输入要扩大的倍数：\n");
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
	printf("数组所有偶数位置求和结果是：%d\n",sum);
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
	printf("数组最大的元素是是：%d\n",max);
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
	printf("数组最小的元素是是：%d\n",min);
}
void look(int *p, int n)
{
	int z;
	int j;
	printf("请输入要查找的元素：\n");
	scanf("%d",&z);
	for(j=0;j<n;j++)
	{
		if(z==*(p+j))
		{
			printf("查找成功：%d\n",z);
			break;
		}

	}
	if(j==n)
		printf("查找失败：%d\n",z);
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