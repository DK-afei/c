#include <stdio.h>
#include <malloc.h>
#define MaxLen 100
typedef struct
{
	char data[MaxLen];
	int top;
}sqstacktp;
void InitStack(sqstacktp *s)
{
	s->top=0;
}
int StackEmpty(sqstacktp *s)
{
	if(s->top>0)
		return 0;
	else
		return 1;
}
void Push(sqstacktp *s,char c)
{
	if(s->top==MaxLen)
		printf("Overflow");
	else
		s->data[s->top++]=c;
}
char Pop(sqstacktp *s)
{
	if(s->top==0)
		return '\0';
	else
	{
		s->top--;
		return s->data[s->top];
	}
}
int Size(sqstacktp *s)
{
	return(s->top);
}
char Top(sqstacktp *s)
{
	if(s->top==0)
		return '\0';
	else
		return (s->data[s->top-1]);
}
int judge(char *str,sqstacktp *s)
{
	int i=0;
	while(str[i]!='\0')
	{
		if(str[i]=='('||str[i]==')')
		{
					
				if(StackEmpty(s)||str[i]==Top(s))
				Push(s,str[i]);
				else
					Pop(s);
		}
		i++;
	}
	i=0;
		while(str[i]!='\0')
	{
		if(str[i]=='['||str[i]==']')
		{
					
				if(StackEmpty(s)||str[i]==Top(s))
				Push(s,str[i]);
				else
					Pop(s);
		}
		i++;
	}
			i=0;
		while(str[i]!='\0')
	{
		if(str[i]=='{'||str[i]=='}')
		{
					
				if(StackEmpty(s)||str[i]==Top(s))
				Push(s,str[i]);
				else
					Pop(s);
		}
		i++;
	}
	if(StackEmpty(s))
		return 1;
	else
		return 0;

}
void main()
{
	char str[MaxLen];
	sqstacktp *s;
	s=(sqstacktp*)malloc(sizeof(sqstacktp));
	InitStack(s);
	printf("input a string:");
	scanf("%s",str);
	if(judge(str,s)==1)
		printf("%s is a right match\n",str);
	else 
		printf("%s is a false match\n",str);
}