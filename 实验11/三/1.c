#include <stdio.h>
#define N 1000
void main()
{
	FILE*fpt;
	int b[N],d,i,k;
	 if((fpt=fopen("st.dat","r"))==NULL)
	 {
		 printf("Can't open file st.dat.\n");
		 return;
	 }
	 k=0;
	 while(fscanf(fpt,"%d",&b[k])==1)
	 {
		 b[k]=d;
		 for(i=0;b[i]!=d;i++)
			 if(b[i]!=b[k])
				 k++;
	 }
	fclose(fpt);
	for(i=0;i<k;i++)
	{
		printf("%d",b[i]);
	}
	printf("\n");
}
        