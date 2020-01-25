#include <stdio.h>
#define N 10
void input(int *p);
void deal(int *p);
void output(int *p);
int main()
{
	int a[N];
	input(a);
	deal(a);
	output(a);
	return 0;
}
void input(int *p)
{
	int i;
	printf("please input %d numbers:\n",N);
	for(i=0;i<N;i++)
		scanf("%d",p+i);
}
void deal(int *p)
{
	int i,min,max,t;
	min=max=*p;
	for(i=0;i<N;i++)
	{
		if(*(p+i)>max)
			max=*(p+i);
		if(*(p+i)<min)
			min=*(p+i);
	}
	for(i=0;i<N;i++)
	{
		if(*(p+i)==min)
		{
			t=*(p+i);
			*(p+i)=*p;
			*p=t;
		}
	}
	for(i=0;i<N;i++)
	{
		if(*(p+i)==max)
		{
			t=*(p+i);
			*(p+i)=*(p+N-1);
			*(p+N-1)=t;
		}
	}
}
void output(int *p)
{
	int i;
	printf("dealed results are :\n");
	for(i=0;i<N;i++)
		printf("%d ",*(p+i));
	printf("\n");
}
