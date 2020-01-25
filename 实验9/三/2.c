#include  <stdio.h>
void merge(int a[4],int n,int b[5],int m, int*c)
{
	int i,j;
	for(i=j=0;i<n&&j<m;)
		*c++=a[i]<b[j]?a[i++]:b[j++];
	while(i<n)
	*c++=a[i++];
	while(j<m)
		*c++=b[j++];
}
void main()
{
    int a[4]={0,1,2,3};
	int b[5]={4,5,6,7,8};
	int c[9];
    int i;
	merge(a,4,b,5,c);
	for(i=0;i<9;i++)
	printf("%d",c[i]);
	printf("\n");
}
