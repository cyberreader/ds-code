#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct tree
{
	int data;
	struct tree *left,*right;
}TREE;

TREE* create(TREE*,int);
void level_printing(TREE *);

int main()
{
	TREE *root = NULL;

	printf("\n Enter No. of Nodes : ");
	scanf("%d",&n);
	
	while(n>0)
	{
		printf("\n Enter Data : ");
		scanf("%d",&no);
		root = create(root,no);
		n--;
	}
	
	level_printing(root);
		
	return 0;
}

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

void CurrentLevel(TREE *temp, int level) 
{
  	if (temp == NULL)
    {
		return;
	}
  	if (level == 1)
  	{
	  	printf(" %d ", temp -> data);
	}
  	else if (level > 1) 
	{
    	CurrentLevel(temp->left, level-1);
    	CurrentLevel(temp->right, level-1);
    }
}

void level_printing(TREE *temp) 
{
  	int h = height(temp);
  	int i;

  	for (i = 1; i <= h; i++)
  	{
  	    CurrentLevel(temp, i);
  	    printf("\n");
	}
}
