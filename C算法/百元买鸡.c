#include <stdio.h>
void main()
{

			int gj,mj,xj,count=0;
			for(gj=1;gj<33;gj++)
			{
					count++;
				for(mj=1;mj<100;mj++)
				{

					for(xj=3;xj<100;xj=xj+3)
					{
					if( ((gj+mj+xj)==100) &&((gj*3+mj*1+xj/3)==100)&&(xj%3==0) )

					printf("���� %d ֻ��ĸ�� %d ֻ��С�� %d ֻ\n",gj,mj,xj);
					}
				}

			}
		printf("����=%d\n",count);	
}		
	

