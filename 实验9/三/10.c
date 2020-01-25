#include <stdio.h>
int main()
{
		char str[100];
		int n;
		int i;
		int j;
		int k;
		i = 0;
		gets(str);
		while(str[i])
{
		if('0'<=str[i] && str[i]<='9')
{
		j = i;
		while('0'<=str[j] && str[j]<='9')
{
			j++;
}
			k = j;
			n = 0;
			j = i;
		while(j<k)
{
			n = n*10 + str[j] - '0';
			j++;
}
			printf("%d\n",n);
			i = k;
			continue;
}
			i++;
}
			return 0;
}
