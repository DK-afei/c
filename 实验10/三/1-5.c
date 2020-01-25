#include <stdio.h>
#define N 1
struct 
{
	int n1;
	char name[20]; 
	int n;	
	int n2;
}parts[N];
void main()
{
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%d",&parts[i].n1);
		scanf("%s",&parts[i].name);
		scanf("%d",&parts[i].n);
		scanf("%d",&parts[i].n2);
	}
	for(i=0;i<N;i++)
	{
		printf("%d\t\t",parts[i].n1);
		printf("%s\t",parts[i].name);
		printf(" %d\t\t",parts[i].n);
		printf("   %d\n",parts[i].n2);
	}
	printf("\n");
}