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

void postorder(TREE *temp)
{
	if(temp != NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf(" %d ",temp->data);
	}
}

TREE* minValueNode(TREE *temp)
{
    while (temp && temp->left!=NULL)
    {
    	temp = temp->left;
    }
 
    return temp;
}

TREE* deleteNode(TREE *temp, int key)
{
    if (temp == NULL)
    {
	    return temp;
	}
 
    if (key < temp->data)
    {
	    temp->left = deleteNode(temp->left, key);
	}
    else if (key > temp->data)
    {
	    temp->right = deleteNode(temp->right, key);
	}
    else 
	{
        if (temp->left == NULL) 
		{
            TREE *t = temp->right;
            free(temp);
            return t;
        }
        else if (temp->right == NULL) 
		{
            TREE *t = temp->left;
            free(temp);
            return t;
        }
 
        TREE *t = minValueNode(temp->right);
 
        temp->data = temp->data;
 
        temp->right = deleteNode(temp->right, t->data);
    }
    return temp;
}

int main()
{
	TREE *root = NULL;

	int ch,n,no;

	do
	{
		printf("\n 1: CREATE");
		printf("\n 2: PREORDER");
		printf("\n 3: Delete");
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
			
			case 3: printf("\n Enter Data to Delete : ");
				 	scanf("%d",&n);
				 	deleteNode(root, n);
				break;

			case 4: exit(0);
		}
	}while(1);
	
	return 0;
}

