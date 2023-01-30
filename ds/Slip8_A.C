#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct tree
{
	int data;
	struct tree *left,*right;
}TREE;

TREE* create(TREE *temp, int no)
{
	if(temp==NULL)
	{
		temp = (TREE *) malloc(sizeof(TREE));
		temp->data = no;
		temp->left = NULL;
		temp->right = NULL;

		return temp;
	}
	if(no < temp->data)
	{
		temp->left = create(temp->left,no);
	}
	else if(no > temp->data)
	{
		temp->right = create(temp->right,no);
	}

	return temp;
}

void preorder(TREE *temp)
{
	if(temp != NULL)
	{
		printf(" %d ",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}

void search(TREE *temp,int no)
{
	if(temp!=NULL)
	{
		if(temp->data==no)
		{
			printf("\n Element Found");
			return;
		}
		else if(no < temp->data)
		{
			search(temp->left,no);
		}
		else 
		{
			search(temp->right,no);
		}
	}
	else
	{
		printf("\n Element Not Found");
	}
}

int main()
{
	TREE *root = NULL;

	int ch,n,no;

	do
	{
		printf("\n 1: CREATE");
		printf("\n 2: PREORDER");
		printf("\n 3: Search");
		printf("\n 4: EXIT");

		printf("\n Enter your choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: printf("\n Enter No. of Nodes : ");
					scanf("%d",&n);
					while(n>0)
					{
						printf("\n Enter Data : ");
						scanf("%d",&no);
						root = create(root,no);
						n--;
					}
				break;
				
			case 2: preorder(root);
				break;
			
			case 3: printf("\n Enter element to search : ");
					scanf("%d",&n);
					search(root,n);
				break;

			case 4: exit(0);
		}
	}while(1);
	
	return 0;
}

