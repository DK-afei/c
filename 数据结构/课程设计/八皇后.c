#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
static int iCount = 0;						//ȫ�ֱ���
static int WeiZhi[8];						//ȫ������
void Output()						//�����
{
	   int i,j,flag=1;
	   printf("��%2d�ַ���(���ʾ�ʺ�):\n", ++iCount);//�����š� 
	   printf("  ");
	   for(i=1;i<=8;i++)
	   {
		  printf("�x");
	   }
	   printf("\n");
	   for (i = 0; i < 8; i++)
	   {
		   printf("��");
		   for (j = 0; j < 8; j++)
		   {
			   if(WeiZhi[i]-1 == j)
			   {
				   printf("��");			//�ʺ��λ��
			   }
			   else
			   {
				   if (flag<0)
				   {
					   printf("  ");		//���
				   }
				   else
				   {
					   printf("��");    		//���            
				   }
			   }
			   flag=-1*flag;
		   }
		   printf("��\n");
		   flag=-1*flag;
	   }
	   printf("  ");
	   for(i=1;i<=8;i++)
	   {
		   printf("��");
	   }
	   printf("\n");  
}

void EightQueen(int n)				// �㷨
{
	   int i,j;
	   int ct;							//�����ж��Ƿ��ͻ
	   if (n == 8)						//��8���ʺ��ѷ������
	   {
		   Output(); 					//������Ľ��
		   return;
	   }
	   for (i = 1; i <= 8; i++)				//��̽
	   { 
		   WeiZhi[n] = i;					//�ڸ��еĵ�i���Ϸ���
		   //�ϵ�n���ʺ��Ƿ���ǰ��ʺ��γɹ���
		   ct=1;
		   for (j = 0; j < n; j++) 
		   {
			   if (WeiZhi[j] == WeiZhi[n])		// �γɹ���
			   {
				   ct=0;
			   }
			   else if (abs(WeiZhi[j] - WeiZhi[n]) == (n - j))// �γɹ���
			   {
				   ct=0;
			   }
			   else
			   {
			   }
		   }
		   
		   if (ct==1)					//û�г�ͻ���Ϳ�ʼ��һ�е���̽
			   EightQueen(n + 1); 		//�ݹ����
	   }
}
int main()
{
	printf("�˻ʺ�������⣡\n"); 
		  printf("�˻ʺ����з���:\n"); 
		  EightQueen(0);					//���
		  return 0;
}

