#include <stdio.h>
void main()
{
	FILE*fp;
	char ch;
	long pos;
	if((fp=fopen("file.txt","w+"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	ch=getchar();
	while(ch!='\n')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	rewind(fp);
	pos=ftell(fp);
	ch=fgetc(fp);
	while(!feof(fp))
	{	
		printf("%c,%ld\n",ch,pos);
		pos=ftell(fp);
		ch=fgetc(fp);
		
	}
	/*	pos=ftell(fp);
	while((ch=fgetc(fp))!=EOF)
	{
		printf("%c,%ld\n",ch,pos);
		pos=ftell(fp);
		ch=fgetc(fp);
	}*/
	fclose(fp);
	/*if(ferror(fp))
	{
		printf("Error on file!\n");
	}*/
}