#include<stdio.h>
#include<malloc.h>

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

int main()
{
	char str[100];
	int i,j;
	
	init();
	
	printf("\n Enter String : ");
	gets(str);
	
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=' ')
		{
			push(str[i]);
		}
		else
		{
			while(top!=NULL)
			{
				printf("%c",pop());
			}
		}
	}
	
	while(top!=NULL)
	{
		printf("%c",pop());
	}
		
	return 0;
}
