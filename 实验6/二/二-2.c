#include <stdio.h>
#define N 1024
void main()
{
	char a[N];
	char max;
	int i,n;

	printf("������Ҫ������ַ�����Ŀ��");
	scanf("%d",&n);
	printf("�������ַ�����");

	for(i=0;i<n+1;i++)
		scanf("%c",&a[i]);

	max='0';	
	for(i=0;i<n+1;i++)
	{
		if(max<a[i])
			max=a[i];
	}
	
		printf("%c",max);
		printf("\n");

}