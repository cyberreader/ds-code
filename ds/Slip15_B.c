#include<stdio.h>
#include<malloc.h>
#include<process.h>

typedef struct stack
{
	int data;
	struct stack *next;
}STACK;

STACK *top, *temp;

void init()
{
	top = NULL;
}

int isempty()
{
	if(top==NULL)
	{
		return 1;
	}
	return 0;
}

// Add first node
void push()
{
	temp = (STACK*) malloc(sizeof(STACK));
	
	printf("\n Enter Data : ");
	scanf("%d",&temp->data);
	
	temp->next = top;
	top = temp;
}

// Del first node
int pop()
{
	int ele;
	
	temp = top;
	top = top->next;
	ele = temp->data;
	free(temp);
		
	return ele;		
}

// Display nodes
void display()
{
	if(top==NULL)
	{
		printf("\n Stack is empty");
	}
	else
	{
		for(temp=top;temp!=NULL;temp=temp->next)
		{
			printf("\n %d",temp->data);
		}
	}
}

int main()
{
	int ch;
	
	do
	{
		printf("\n 1) Push");
		printf("\n 2) Pop");
		printf("\n 3) Display");
		printf("\n 4) Exit");
		printf("\n Enter your choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: push();
					break;
			case 2: if(isempty())
					{
						printf("\n Stack is empty");
					}
					else
					{
						printf("\n Poped element is : %d",pop());
					}
				
					break;
			case 3: display();
					break;
			case 4: exit(0);		
		}	
	}while(1);
	
	return 0;
}
