#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 100
typedef int elemtype;
typedef struct 
{
	int i,j;
	elemtype v;
}node;
typedef struct
{
	int mu,nu,tu;
	node data[M];
}mat;
mat input(int a, int b, int c)
{
	int i,j;
	int m,n,k;
	mat t;
	t.mu=a;
	t.nu=b;
	t.tu=c;
	printf("please init the datas:\n");
	for(i=0;i<a;i++)
	{
	
		for(j=0;j<b;j++)
		{
			t.data[i*b+j].i=i;
			t.data[i*b+j].j=j;
		}
	}
	for(m=0;m<a*b;m++)
		t.data[m].v=0;
	while(1)
	{
		scanf("%d%d%d",&m,&n,&k);
		if(k==0)
			break;
		else
		{
			for(i=0;i<a;i++)
			{
			
				for(j=0;j<b;j++)
				{
					if(t.data[i*b+j].i==m&&t.data[i*b+j].j==n)
						t.data[i*b+j].v=k;
				}
			}
		}
	}
	return t;
}
void output(mat a)
{
	int i,j;
	printf("the %d * %d mat of %d datas is:\n",a.mu,a.nu,a.tu);
	for(i=0;i<a.mu;i++)
	{
		for(j=0;j<a.nu;j++)
		{
			printf("%d ",a.data[i*a.nu+j].v);
		}
			printf("\n");
	}
}
mat add(mat a, mat b)
{
	mat c;
	int i;
	c.mu=a.mu;
	c.nu=a.nu;
	c.tu=0;
	for(i=0;i<a.mu*a.nu;i++)
	{
		c.data[i].v=a.data[i].v+b.data[i].v;
		if(c.data[i].v!=0)
			c.tu++;
	}
	return c;
}
mat sub(mat a, mat b)
{
	mat c;
	int i;
	c.mu=a.mu;
	c.nu=a.nu;
	c.tu=0;
	for(i=0;i<a.mu*a.nu;i++)
	{
		c.data[i].v=a.data[i].v-b.data[i].v;
		if(c.data[i].v!=0)
			c.tu++;
	}
	return c;
}
int mul(mat a, mat b)
{
	int i,j,k;
	int L=0;
	int sum=0;
	L=a.mu-1;
	for (i = 0; i <= L; i++)
	{
		for (j = 0; j <= L; j++) 
		{
			for (k = 0; k <= L; k++) 
			{
				sum += a.data[i*a.mu+k].v*b.data[k*b.mu+j].v;
			}
		}
	}
	return sum;
}
int main()
{
	mat a, b;
	a=input(2,2,2);
	b=input(2,2,2);
	output(a);
	output(b);
	output(add(a,b));
	output(sub(a,b));
	printf("%d\n",mul(a,b));
	return 0;
}