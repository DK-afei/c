#include <stdio.h>
void main()
{
	char ch='0',ch1;
	int i,j;
		printf ("������һ����д��ĸ��");
		ch=getchar(); 
		getchar(); 
		while(ch<'A'||ch>'Z')
		{
			printf ("������Ĳ��Ǵ�д��ĸ������������:\n");
			ch=getchar(); 
			getchar();
		}
		for(i=0;i<ch-'A'+1;i++)
		{
			for(j=0;j<ch-'A'-i;j++)
			{
				printf(" ");
			}	
				for(j=0;j<i+1;j++)
			{
					ch1='A'+j;
				printf("%c",ch1);
			}	
				for(j=0;j<i;j++)
			{
					printf("%c",ch1-j-1);
			}
		printf("\n");			
		}
		

}
		