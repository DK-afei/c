#include <stdio.h>
void main()
{
	FILE*fp;
	char ch,a[1024];
	int i,t=0;
	if((fp=fopen("C:\\Users\\Administrator\\Desktop\\新建文件夹\\3\\text.txt","r"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		putchar(ch);
		a[t]=ch;
		t++;
		ch=fgetc(fp);
	}
	for(i=0;i<t;i+=2)
		printf("%c",a[i]);
	printf("\n");
	fclose(fp);
}