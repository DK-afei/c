#include <stdio.h>
void main()
{
	FILE*fp;
	int j,a[100]={0},b[10]={0},t=1,sum=0;
	if((fp=fopen("C:\\Users\\Administrator\\Desktop\\新建文件夹 (2)\\file2.txt","r"))==NULL)
	{
		printf("Can't open the file!");
		return;
	}
		fscanf(fp,"%d",&a[0]);
		for(j=1;a[j]!=EOF;j++)
		{
		fscanf(fp,"%d",&a[j]);
		}
		b[0]=a[0];
		for(j=0;;j++)
	{
		if(a[j]==0)
		break;
		if(j>0&&a[j]<10)
		{
		printf("\n");
		b[t]=a[j];
		t++;
		}
		printf("%d ",a[j]);
	}
		j=0;
		t=1;
		while(a[j]!=0)
		{
			
			if(a[j]>10)
			{
			sum+=a[j];
			
			}
			if(j>0&&a[j]<10)
			{
			printf("\n%.2f\n",(float)sum/b[t-1]);
			sum=0;
			t++;
			}
			j++;
		}
		printf("\n");
		fclose(fp);

}