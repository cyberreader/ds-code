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

void inorder(TREE *temp)
{
	if(temp != NULL)
	{
		inorder(temp->left);
		printf(" %d ",temp->data);
		inorder(temp->right);
	}
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

int main()
{
	TREE *root = NULL;

	int ch,n,no;

	do
	{
		printf("\n 1: CREATE");
		printf("\n 2: INORDER");
		printf("\n 3: PREORDER");
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
				
			case 2: inorder(root);
				break;
			
			case 3: preorder(root);
				break;

			case 4: exit(0);
		}
	}while(1);
	
	return 0;
}

