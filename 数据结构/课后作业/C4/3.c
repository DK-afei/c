#include<stdio.h>
#include<string.h>
void main()
{
	char s1[100],s2[10];
	int i,j,k,len1,len2,b[10];
	gets(s1);
	gets(s2);
	len1=strlen(s1);
	len2=strlen(s2);
	for(i=0,k=0;i<len1;i++)
	{
	for(j=0;j<len2;j++)
	if(s1[i+j]!=s2[j]) break;
	if(j>=len2)  
		   b[k++]=i+1;  //i��0��ʼ�����ģ�����λ����i+1
	}
	printf("%d\n",k);    //kΪs2��s1�г��ֵĴ���
	for(i=0;i<k;i++)
	printf("%d ",b[i]);  //����s2��s1�е�λ��,�����ж��
	printf("\n");
}
