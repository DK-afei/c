#include <stdio.h>
#include <string.h>
#define N 5
#define M 5
void main()
{
			void change(int *,int);
			int a[N][M],i,*p;
			puts("Input matrix:");
			for(i=0;i<N;i++)
			scanf("%d%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
			p=*a;
			change(p,N*M);
			for(i=0;i<N;i++)
			printf("%-4d %-4d %-4d %-4d %-4d/n",a[i][0],a[i][1],a[i][2],a[i][3],a[i][4]);
			puts("");
}

void change(int *p,int n)
{
			int *max=p,*min=p,*p_begin=p,*p_end=p+n-1,temp;
		while(p_end>p_begin)
{
			 if(*max<*p_end) max=p_end;
			 else if(*min>*p_end)
			 min=p_end;
			 p_end--;
}
			printf("max=%d/n",*max);
			temp=*(p+n/2);*(p+n/2)=*max;*max=temp;
			temp=*p;
			*p=*min;
			*min=temp;

			min=p+1;
		for(p_end=p+n-1;p+1<p_end;p_end--)
			if(*min>*p_end) 
			 min=p_end;
			temp=*(p+4);
			*(p+4)=*min;
			*min=temp;

			min=p+1;
		for(p_end=p+n-1;p+1<p_end;p_end--)
			if((p_end!=p+4)&&(*min>*p_end)) 
			 min=p_end;
			temp=*(p+20);
			*(p+20)=*min;
			*min=temp;
			min=p+1;
		for(p_end=p+n-1;p+1<p_end;p_end--)
			if((p_end!=p+4)&&(p_end!=p+20)&&(*min>*p_end))
			min=p_end;
			temp=*(p+24);
			*(p+24)=*min;
			*min=temp;
			}
