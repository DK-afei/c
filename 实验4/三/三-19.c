#include <stdio.h>
void main()
{

			int dm,zm,xm;
			for(dm=1;dm<33;dm++)
			{
				
				for(zm=1;zm<100;zm++)
				{

					for(xm=2;xm<100;xm=xm+2)
					{
					if( ((dm+zm+xm)==100) &&((dm*3+zm*2+xm/2)==100)&&(xm%2==0) )

					printf("大马%d 匹，中马 %d 匹，小马 %d 匹\n",dm,zm,xm);
					}
				}

			}
		printf("\n");	
}		
	