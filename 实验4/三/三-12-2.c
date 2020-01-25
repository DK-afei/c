#include <stdio.h>
void main()
{
	char ch='0',ch1;
	int i,j;
		printf ("请输入一个大写字母：");
		ch=getchar(); 
		getchar(); 
		while(ch<'A'||ch>'Z')
		{
			printf ("你输入的不是大写字母，请重新输入:\n");
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
		