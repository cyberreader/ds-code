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

int isempty()
{
	if(s.top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isfull()
{
	if(s.top==MAX-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(char ch)
{
	if(isfull())
	{
		printf("\n Stack is full");
	}
	else
	{
		s.stk[++s.top] = ch;
	}
}

char pop()
{
	if(isempty())
	{
		printf("\n Stack is empty");
		return 0;
	}
	else
	{
		return s.stk[s.top--];
	}
}

int main()
{
	char str[MAX];
	int i;
	
	init();
	
	printf("\n Enter String : ");
	gets(str);
	
	printf("\n String is : %s",str);
	
	for(i=0;str[i]!='\0';i++)
	{
		push(str[i]);
	}
	
	printf("\n After Reverse String is : ");
	while(isempty()==0)
	{
		printf("%c",pop());
	}
	
	return 0;
}
