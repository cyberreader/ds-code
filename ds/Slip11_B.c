#include<stdio.h>
#include<malloc.h>
#include<process.h>

typedef struct queue
{
	int data;
	struct queue *next;
}QUEUE;

QUEUE *front,*rear,*temp;

void init()
{
	front = NULL;
	rear = NULL;
}

int isEmpty()
{
	if(front==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void insert()
{
	temp = (QUEUE*) malloc(sizeof(QUEUE));
	
	printf("\n Enter Data : ");
	scanf("%d",&temp->data);
	
	temp->next = NULL;	
	
	if(rear==NULL)
	{
		front = temp;
	}
	else
	{
		rear->next = temp;
	}
		
	rear = temp;
}

void Delete()
{
	if(isEmpty())
	{
		printf("\n Queue is empty");
	}
	else
	{
		temp = front;
		front = front->next;
		printf("\n Deleted Element is : %d",temp->data);
		free(temp);	
		
		if(front==NULL)
		{
			rear = NULL;
		}
	}
}

void display()
{
	if(isEmpty())
	{
		printf("\n Queue is empty");
	}
	else
	{
		printf("\n Queue Elements are : ");
		
		for(temp=front;temp!=NULL;temp=temp->next)
		{
			printf(" %d ",temp->data);
		}
	}
}

int main()
{
	int ch;
	
	init();
	
	do
	{
		printf("\n 1) Insert");
		printf("\n 2) Delete");
		printf("\n 3) Display");
		printf("\n 4) Exit");
		
		printf("\n Enter Choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:	insert();
					break;
			case 2: Delete();
					break;
			case 3: display();
					break;
			case 4:	exit(0);
		}
	}while(1);
	
	return 0;
}

