#include <stdio.h>
#define N 5
void main()
{
	FILE*fp;
	char ch;
	if((fp=fopen("C:\\Users\\Administrator\\Desktop\\新建文件夹\\3\\text.txt","r"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	fclose(fp);
}