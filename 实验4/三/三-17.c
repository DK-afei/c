#include<stdio.h>
#define N 1000 
int main() 
{ 
						int i,j,k,sum;
						int a[256];
						for(i=2;i<=N;i++)
						{ 
							sum=a[0]=1;
							k=0; 
							for(j=2;j<=(i/2);j++) 
							{ 
								if(i%j==0)
								{ 
									sum+=j;
									a[++k]=j;
								} 
							}
							if(i==sum)
							{ 
								printf("%d 和%d 是亲密对数",i,i);
								printf("\n");
							} 
						}
						return 0; 
}
