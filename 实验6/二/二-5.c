#include <stdio.h>
#define N 1024
void main()
{
	char s[N];
	int i=0,n;
	printf("请输入大写字符的数目：");
	scanf("%d",&n);
	printf("Enter a string. \n");

	scanf("%s",s);
	while(i<n+1)
	{
		if(s[i]>='A'&&s[i]<='Z')
			s[i]=s[i]-'A'+'a';
		i++;
	}
		printf("%s\n",s);
}