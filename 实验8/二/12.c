#include "stdio.h"
#include "string.h"
#include "stdlib.h"
int search(char *list, char c,int len)
{
	int low=0,high=len-1,k;
	while (low<=high)
	{
		k=(int)(low+high)/2;
		if(list[k]==c)
			return k;
		else if(list[k]>c)
			high=k-1;
		else 
			low=k+1;
	}
	return -1;
}
void main()
{
	char a[1024];
	char ch;
	gets(a);
	fflush(stdin);
	ch=getchar();
	printf("%d\n",search(a,ch,(int)strlen(a)));

}