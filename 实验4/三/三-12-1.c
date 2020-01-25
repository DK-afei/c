#include <stdio.h>
int main()
{
		char a,b,c;
		printf ("请输入一个大写字母：");
		a=getchar(); 
		getchar(); 
		while(a<'A'||a>'Z')
		{
			printf ("你输入的不是大写字母，请重新输入:\n");
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
