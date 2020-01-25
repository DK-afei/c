#include <stdio.h>
#define N 1024
void main()
{
	FILE*fp;
	char a[N];
	if((fp=fopen("file.text","w"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	gets(a);
	fputs(a,fp);
	fclose(fp);
}