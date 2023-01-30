#include<stdio.h>
#include<alloc.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *last,*temp;

NODE* create(NODE *head)
{
	int n;

	printf("\n Enter No. of Nodes : ");
	scanf("%d",&n);

	head = NULL;

	while(n>0)
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

	return(head);
}

void display(NODE *head)
{
	printf("\n List is : ");
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		printf(" %d ",temp->data);
	}
}

void Union(NODE *head1,NODE *head2)
{
	int flag;

	printf("\n Union is : ");

	for(temp=head1;temp!=NULL;temp=temp->next)
	{
		printf(" %d ",temp->data);
	}

	for(last=head2;last!=NULL;last=last->next)
	{
		flag = 0;

		for(temp=head1;temp!=NULL;temp=temp->next)
		{
			if(last->data==temp->data)
			{
				flag=1;
				break;
			}
		}

		if(flag==0)
		{
			printf(" %d ",last->data);
		}
	}
}

void intersection(NODE *head1,NODE *head2)
{
	printf("\n Intersection is : ");

	for(last=head2;last!=NULL;last=last->next)
	{
		for(temp=head1;temp!=NULL;temp=temp->next)
		{
			if(last->data==temp->data)
			{
				printf(" %d ",last->data);
				break;
			}
		}
	}
}

int main()
{
	NODE *head1=NULL,*head2=NULL;

	int ch;

	do
	{
		printf("\n--------------------------------------");
		printf("\n 1) Create List1");
		printf("\n 2) Display List1");
		printf("\n 3) Create List2");
		printf("\n 4) Display List2");
		printf("\n 5) Union");
		printf("\n 6) Intersection");
		printf("\n 7) Exit");
		printf("\n Enter your choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: head1 = create(head1);
				break;
			case 2: display(head1);
				break;
			case 3: head2 = create(head2);
				break;
			case 4: display(head2);
				break;
			case 5: Union(head1,head2);
				break;
			case 6: intersection(head1,head2);
				break;
			case 7: exit(0);
			default: printf("\n Invalid Choice");
		}
	}while(1);
	
	return 0;
}

