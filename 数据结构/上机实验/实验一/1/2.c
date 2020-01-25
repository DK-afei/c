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
void zhizhen(int *p,int n)
{
	int j;
	for(j=0;j<n;j++)
		printf("%d ",*(p+j));
	printf("\n");
}
void shanchu(int *p, int n)
{
	int x;
	int b[N];
	int j;
	int m=0;
	printf("请输入要删除的元素：\n");
	scanf("%d",&x);
	for(j=0;j<n;j++)
	{
		if(*(p+j)!=x)
		{
			b[m]=*(p+j);
			m++;
		}
	}
	zhizhen(b,m);
}
void shanchuzhiding(int *p, int n)
{
	int i;
	int b[N];
	int j;
	int m=0;
	printf("请输入要删除的元素的位置：\n");
	scanf("%d",&i);
	for(j=0;j<n;j++)
	{
		if(j!=i)
		{
			b[m]=*(p+j);
			m++;
		}
	}
	zhizhen(b,m);
}
void shanchuxiangtong(int *p,int n)
{
	int b[N];
	int i,j;
	int m=0;
	for(j=0;j<n;j++)
	{
		for(i=j+1;i<n;i++)
		{
			if(*(p+j)!=*(p+i)&&i==n-1)
			{
				b[m]=*(p+j);
				m++;
			}
		}	
	}
	zhizhen(b,m);

}
void add(int *p,int n)
{
	int i;
	int b[N];
	int j;
	int m=0;
	int x;
	printf("请输入要添加的元素的位置：\n");
	scanf("%d",&i);
	printf("请输入要添加的元素：\n");
	scanf("%d",&x);
	for(j=0;j<n;j++)
	{
		m++;
			if(j==i)
		{
			b[j]=x;
			break;
		}
		b[j]=*(p+j);
	
	}
	for(j=i+1;j<n;j++)
	{
		m++;
		b[j]=*(p+j-1);
	
	}
	zhizhen(b,m);
}
void reverse(int *p, int n)
{
	int b[N];
	int j;
	int m=0;
	for(j=0;j<n;j++)
	{
		b[j]=*(p+n-j-1);
		m++;
	}
	zhizhen(b,m);
}
void paixu(int a[], int n)
{
	int i,j;
	int t;
	for(i=n-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	zhizhen(a,n);
}
void tianjiayouxu(int a[], int n)
{
	int b[N];
	int t1,t2,num,end,i,j;
	for(i=0;i<n;i++)
	{
		b[i]=a[i];
	}
	printf("input the added number:\n");
	scanf("%d",&num);
	end=b[n-1];
	if(num>end)
		b[n]=num;
	else
	{
		for(i=0;i<n;i++)
		{
			if(b[i]>num)
			{
				t1=b[i];
				b[i]=num;
				for(j=i+1;j<n+1;j++)
				{
					t2=b[j];
					b[j]=t1;
					t1=t2;
				}
				break;
			}
		}
	}
	zhizhen(b,n+1);
}
int main()
{
	int a[N];
	int num;
	num=init(a);
	zhizhen(a,num);
	/*shanchu(a,num);
	shanchuzhiding(a,num);
	shanchuxiangtong(a,num);
	add(a,num);
	reverse(a,num);
	paixu(a,num);
	tianjiayouxu(a,num);*/
	return 0;
}