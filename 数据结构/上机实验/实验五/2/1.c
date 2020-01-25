#include <stdio.h>
#include <stdlib.h>
#define m 1024
typedef struct bn
{
	int d;
	struct bn *lc, *rc, *p;
}BN;
BN *create()
{
	int x;
	BN *bt;
	scanf("%d",&x);
	if(x==0)return(NULL);
	else
	{
		bt=(BN*)malloc(sizeof(BN));
		bt->d=x;
		bt->lc=create();
		if(bt->lc)
		bt->lc->p=bt;
		bt->rc=create();
		if(bt->rc)
		bt->rc->p=bt;
		return (bt);
	}
}
void preorder(BN *t)
{
	if(t)
	{
		printf("%d",t->d);
		preorder(t->lc);
		preorder(t->rc);
	}
}
int GD(BN *t)
{
	int num=0;
	if(t)
	{
		if(t->lc)
			num++;
			num+=GD(t->lc)+GD(t->rc);
			
	}
	return num;
}
void GSD(BN *t, int x)
{
	if(t->d==x)
	{
		printf("%d\n",GD(t)+1);
	}
	else
	{
		if(t->lc)
			GSD(t->lc,x);
		if(t->rc)
			GSD(t->rc,x);
	}
}
int CL(BN *t)
{
	int i;
	if(t==NULL)
		i=0;
	else if((t->lc==NULL)&&(t->rc==NULL))
		i=1;
	else
		i=CL(t->lc)+CL(t->rc);
	return (i);
}
int HZ(BN *t)
{
	int num=0;
	struct bn *tt;
	if(t)
	{
		if(t->lc)
		{
			tt=t->lc;
			while(tt)
			{
				tt=tt->rc;
				num++;
			}
		}
			
	}
	return num;
}
void HZS(BN *t, int x)
{
	if(t->d==x)
	{
		printf("%d\n",HZ(t));
	}
	else
	{
		if(t->lc)
			HZS(t->lc,x);
		if(t->rc)
			HZS(t->rc,x);
	}
}
void XD(BN *t, int x)
{
	struct bn *tt;
	if(t->d==x)
	{
		tt=t;
		while(1)
		{
			if(tt->p->lc==tt)
			{
				while(tt)
				{
					printf("%d\t",tt->d);
					tt=tt->rc;
				}
				break;
			}
			else
			{
				tt=tt->p;
			}
		}
	}
	else
	{
		if(t->lc)
			XD(t->lc,x);
		if(t->rc)
			XD(t->rc,x);
	}
}
void SS(BN *t, int x)
{

	struct bn *tt;
	if(t->d==x)
	{
		tt=t;
		while(1)
		{
			if(tt->p->lc==tt)
			{
				tt=tt->p;
				while(1)
						{
							if(tt->p->lc==tt)
							{
								while(tt)
								{
									printf("%d\t",tt->d);
									tt=tt->rc;
								}
								break;
							}
							else
							{
								tt=tt->p;
							}
						}
				break;
			}
			else
			{
				tt=tt->p;
			}
		}
	}
	else
	{
		if(t->lc)
		{
			SS(t->lc,x);
		}
		if(t->rc)
		{
			SS(t->rc,x);
		}
	}
}
//1 2 0 3 4 0 0 5 0 0 0 
int main()
{
	BN *bn;
	bn=create();
	preorder(bn);
	printf("\n");
	printf("%d\n",GD(bn)+1);
	GSD(bn,2);
	HZS(bn,3);
	XD(bn,5);
	printf("\n");
	printf("%d\n",CL(bn));
	SS(bn,4);;
	printf("\n");
	return 0;
}