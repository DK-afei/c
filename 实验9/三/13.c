#include <stdio.h>
void josephu(int*people)
{
		int n;
		int i, j;
		for(i = 0; i < 30; i++) 
			*(people+i) = i+1; 
		i = 0;
		n = 30;
		while(n > 15)
		{
			i += 8;
			i %= n;
			printf("扔下第 %d 人\n",*(people+i));
			n --;
			for(j = i; j < n; j++)
			{
			*(people+j) = *(people+j+1);
		}
		printf("剩下的人: ");
		for(j=0;j<n;j++) 
		{
		  if(j == i)
			printf("*%d ", *(people+j));
	    	else
			printf("%d ", *(people+j));
		}
		printf("\n");
		}
}
int main()
{
		int people[30];
		josephu(people);
		return 0;
}
