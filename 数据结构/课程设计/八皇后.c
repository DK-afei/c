#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
static int iCount = 0;						//全局变量
static int WeiZhi[8];						//全局数组
void Output()						//输出解
{
	   int i,j,flag=1;
	   printf("第%2d种方案(★表示皇后):\n", ++iCount);//输出序号。 
	   printf("  ");
	   for(i=1;i<=8;i++)
	   {
		  printf("▁");
	   }
	   printf("\n");
	   for (i = 0; i < 8; i++)
	   {
		   printf("▕");
		   for (j = 0; j < 8; j++)
		   {
			   if(WeiZhi[i]-1 == j)
			   {
				   printf("★");			//皇后的位置
			   }
			   else
			   {
				   if (flag<0)
				   {
					   printf("  ");		//棋格
				   }
				   else
				   {
					   printf("█");    		//棋格            
				   }
			   }
			   flag=-1*flag;
		   }
		   printf("▏\n");
		   flag=-1*flag;
	   }
	   printf("  ");
	   for(i=1;i<=8;i++)
	   {
		   printf("▔");
	   }
	   printf("\n");  
}

void EightQueen(int n)				// 算法
{
	   int i,j;
	   int ct;							//用于判断是否冲突
	   if (n == 8)						//若8个皇后已放置完成
	   {
		   Output(); 					//输出求解的结果
		   return;
	   }
	   for (i = 1; i <= 8; i++)				//试探
	   { 
		   WeiZhi[n] = i;					//在该列的第i行上放置
		   //断第n个皇后是否与前面皇后形成攻击
		   ct=1;
		   for (j = 0; j < n; j++) 
		   {
			   if (WeiZhi[j] == WeiZhi[n])		// 形成攻击
			   {
				   ct=0;
			   }
			   else if (abs(WeiZhi[j] - WeiZhi[n]) == (n - j))// 形成攻击
			   {
				   ct=0;
			   }
			   else
			   {
			   }
		   }
		   
		   if (ct==1)					//没有冲突，就开始下一列的试探
			   EightQueen(n + 1); 		//递归调用
	   }
}
int main()
{
	printf("八皇后问题求解！\n"); 
		  printf("八皇后排列方案:\n"); 
		  EightQueen(0);					//求解
		  return 0;
}

