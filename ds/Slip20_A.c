#include<stdio.h>

#define MAX 100

typedef struct stack
{
	char stk[MAX];
	int top;
}STACK;

STACK s;

void init()
{
	s.top = -1;
}

void push(char ch)
{
	s.stk[++s.top] = ch;
}

char pop()
{
	return s.stk[s.top--];
}

int main()
{
	char str[MAX],rev[MAX];
	int i;
	
	init();
	
	printf("\n Enter String : ");
	gets(str);
	
	for(i=0;str[i]!='\0';i++)
	{
		push(str[i]);
	}
	
	for(i=0;isempty()==0;i++)
	{
		rev[i] = pop();
	}
	
	rev[i] = '\0';
	
	if(strcmpi(str,rev)==0)
	{
		printf("\n String is Palindrome");
	}
	else
	{
		printf("\n String is not Palindrome");
	}
	
	return 0;
}
