#include <stdio.h>
int main()
{
		char a,b,c;
		printf ("������һ����д��ĸ��");
		a=getchar(); 
		getchar(); 
		while(a<'A'||a>'Z')
		{
			printf ("������Ĳ��Ǵ�д��ĸ������������:\n");
			a=getchar(); 
			getchar();
		}
		for(c='A';c<=a;c++) 
		{
			for(b=a;b>c;b--) 
			printf(" ");
			for(b='A';b<c;b++) 
			printf("%c",b);
			for(;b>='A';b--) 
			printf("%c",b);
			printf("\n");
		}
		return 0;
}
