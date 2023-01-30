#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *prev,*next;
}NODE;

NODE *head=NULL,*last,*temp;

void create()
{
	int n;

	printf("\n Enter No. of Nodes : ");
	scanf("%d",&n);

	while(n>0)
	{
		temp = (NODE*) malloc(sizeof(NODE));
		
		printf("\n Enter Data : ");
		scanf("%d",&temp->data);
		
		if(head==NULL)
		{
			head = temp;
		}
		else
		{
			last->next = temp;
			temp->prev = last;
		}

		last = temp;
		
		head->prev = last;
		last->next = head;

		n--;
	}
}

void display()
{
	printf("\n Forward List is : %d ",head->data);
	for(temp=head->next;temp!=head;temp=temp->next)
	{
		printf(" %d ",temp->data);
	}
	
	printf("\n Backward List is : ");
	
	for(temp=head;temp->next!=head;temp=temp->next);

	for(;temp!=head;temp=temp->prev)
	{
		printf(" %d ",temp->data);
	}
	
	printf(" %d ",temp->data);
}

int main()
{
	int ch;

	do
	{
		printf("\n 1) Create");
		printf("\n 2) Display");
		printf("\n 3) Exit");

		printf("\n Enter your choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: create();
				break;
			case 2: display();
				break;
			case 3: exit(0);
			default: printf("\n Invalid Choice");
		}
	}while(1);
	
	return 0;
}	
