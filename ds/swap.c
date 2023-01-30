#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *head,*last,*temp;

void create()
{
	int n;

	printf("\n Enter No. of Nodes : ");
	scanf("%d",&n);

	head = NULL;

	while(n>=1)
	{
		temp = (NODE*) malloc(sizeof(NODE));

		printf("\n Enter Data : ");
		scanf("%d",&temp->data);

		temp->next = NULL;

		if(head==NULL)
		{
			head = temp;
		}
		else
		{
			last->next = temp;
		}

		last = temp;

		n--;
	}
}

void display()
{
	printf("\n List is : ");

	for(temp=head;temp!=NULL;temp=temp->next)
	{
		printf(" %d ",temp->data);
	}
}

void swap()
{
	int p1,p2,t;

	printf("\n Enter Position 1 & Position 2 : ");
	scanf("%d%d",&p1,&p2);

	for(last=head;p1>1;last=last->next)
	{
		p1--;
	}

	for(temp=head;p2>1;temp=temp->next)
	{
		p2--;
	}

	t = last->data;
	last->data = temp->data;
	temp->data = t;
}

int main()
{
	create();
	
	printf("\n Before Swapping : ");
	display();
	
	swap();
	
	printf("\n After Swapping : ");
	display();
	
	return 0;
}
