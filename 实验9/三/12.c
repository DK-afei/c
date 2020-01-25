#include <stdio.h>
void main()
{
		int nMonth;
	char*pMonth[12]={{"January"},{"February"},{"March"},{"April"},{"May"},{"June"},{"July"},{"August"},{"Sepetember"},{"October"},{"November"},{"December"}};
	while(1)
	{
		printf("please input month number(illegal month will exit):\n\t");
		scanf("%d",&nMonth);
		if(nMonth<1||nMonth>12)
			break;
		printf("\t%s\n",*(pMonth+nMonth-1));
	}
	
}
