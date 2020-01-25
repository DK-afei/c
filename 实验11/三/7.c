#include <stdio.h>
#define M 2
#define N 1024
void main()
{
	FILE*fp;
	char ch;
	int i=0;
	if((fp=fopen("text.txt","r"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		
		if(ch=='\n')
		{
			if(i==M)
				break;
			printf("\n%d:",i+1);
		i++;
		
		}
		putchar(ch);
		ch=fgetc(fp);
		
	}
	printf("\n");
	fclose(fp);
}
