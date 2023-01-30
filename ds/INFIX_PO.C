#include<stdio.h>
#include<string.h>

#define MAX 100

typedef struct stack
{
	char stk[MAX];
	int top;
}STACK;

STACK s;

void init()
{
	s.top=-1;
}

void push(char);
char pop();

int precedence(char);

char ch;

int main()
{
	char inf[MAX],pre[MAX];
	int i,k=0;
	int isp,icp;

	printf("\n Enter the Infix Expression : ");
	scanf("%s",&inf);

	for(i=0;inf[i]!='\0';i++)
	{
		if(inf[i] != '+' && inf[i] != '-' && inf[i] != '*' && inf[i] != '/' && inf[i] != '%' && inf[i] != '^' && inf[i] != '$' && inf[i] != '(' && inf[i] != ')')
		{
			pre[k] = inf[i];
			k++;
			continue;
		}

		if(inf[i] == '(')
		{
			push('(');
			continue;
		}

		if(inf[i] == ')')
		{
			while((ch = pop()) != '(')
			{
				pre[k] = ch;
				k++;
			}
			
			continue;
		}
		
		if(inf[i] == '+' || inf[i] == '-' || inf[i] == '*' || inf[i] == '/' || inf[i] == '%' || inf[i] == '^' || inf[i] == '$')
		{
			if(s.top == -1)
			{
				push(inf[i]);
				continue;
			}

			isp = precedence(s.stk[s.top]);
			icp = precedence(inf[i]);

			while(isp >= icp)
			{
				pre[k] = pop();
				k++;

				isp = precedence(s.stk[s.top]);
			}

			push(inf[i]);
		}
	}

	while(s.top != -1)
	{
		pre[k] = pop();
		k++;
	}

	pre[k] = '\0';

	printf("prefix Expr. : %s",pre);

	return 0;
}

void push(char ch)
{
	if(s.top == MAX-1)
	{
		printf("\n\n\t Stack is Full...");
	}
	else
	{
		s.stk[++s.top] = ch;
	}
}

char pop()
{
	return(s.stk[s.top--]);
}

int precedence(char op)
{
	switch(op)
	{
		case '+':
		case '-': return 1;

		case '*':
		case '/':
		case '%': return 2;

		case '^':
		case '$': return 3;

		default : return -1;
	}
}

