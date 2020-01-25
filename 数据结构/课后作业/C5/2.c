#include <stdio.h>
#include <stdlib.h>
typedef struct bn
{
	char d;
	struct bn *lc, *rc;
}BN;
BN *create()
{
	char ch;
	BN *bt;
	ch=getchar();
	if(ch=='#')return(NULL);
	else
	{
		bt=(BN*)malloc(sizeof(BN));
		bt->d=ch;
		bt->lc=create();
		bt->rc=create();
		return (bt);
	}
}
void inorder(BN *t)
{
	if(t)
	{
		inorder(t->lc);
		printf("%c",t->d);
		inorder(t->rc);
	}
}
void postorder(BN *t)
{
	if(t)
	{
		postorder(t->lc);
		postorder(t->rc);
		printf("%c",t->d);
	}
}
int main()
{
	BN *bn;
	bn=create();
	inorder(bn);
	printf("\n");
	postorder(bn);
	printf("\n");
	return 0;
}