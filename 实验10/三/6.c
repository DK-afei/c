#include <stdio.h>
#define N 5
struct car
{
	int num;
	int mile;
	int gal;
}cars[N];
void main()
{
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%d",&cars[i].num);
		scanf("%d",&cars[i].mile);
		scanf("%d",&cars[i].gal);
	}
	printf("�������ƺţ�\t��ʻ��Ӣ������\t���ĵļ�������\n");
	for(i=0;i<N;i++)
	{
		printf("    %d\t\t",cars[i].num);
		printf("    %d\t",cars[i].mile);
		printf("    %d\n",cars[i].gal);
	}
	printf("\n");
}