#include<stdio.h>
#include<string.h>
#include<malloc.h>

#define MAX 100

typedef struct stack
{
	char data;
	struct stack *next;
}STACK;

STACK *top, *temp;

void init()
{
	top = NULL;
}

void push(char ch)
{
	temp = (STACK*) malloc(sizeof(STACK));
	
	temp->data = ch;

	temp->next = top;
	top = temp;
}

char pop()
{
	char ch;
		
	temp = top;
	ch = temp->data;
	top = top->next;
	free(temp);
	return ch;
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

int main()
{
	char inf[MAX],post[MAX],ch;
	int i,k=0;
	int isp,icp;

	printf("\n Enter the Infix Expression : ");
	scanf("%s",&inf);

	for(i=0;inf[i]!='\0';i++)
	{
		if(inf[i] != '+' && inf[i] != '-' && inf[i] != '*' && inf[i] != '/' && inf[i] != '%' && inf[i] != '^' && inf[i] != '$' && inf[i] != '(' && inf[i] != ')')
		{
			post[k] = inf[i];
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
				post[k] = ch;
				k++;
			}
			
			continue;
		}
		
		if(inf[i] == '+' || inf[i] == '-' || inf[i] == '*' || inf[i] == '/' || inf[i] == '%' || inf[i] == '^' || inf[i] == '$')
		{
			if(top == NULL)
			{
				push(inf[i]);
				continue;
			}

			isp = precedence(top->data);
			icp = precedence(inf[i]);

			while(isp>=icp)
			{
				post[k] = pop();
				k++;

				if(top!=NULL)
				{
					isp = precedence(top->data);
				}
				else
				{
					isp=-1;
				}
			}

			push(inf[i]);
		}
	}

	while(top != NULL)
	{
		post[k] = pop();
		k++;
	}

	post[k] = '\0';

	printf("postfix Expr. : %s",post);

	return 0;
}

