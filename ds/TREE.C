#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct tree
{
	int data;
	struct tree *left,*right;
}TREE;

TREE* create(TREE*,int);
TREE* insert(TREE*,int);
TREE* deleteNode(TREE*,int);

void nonpostorder(TREE *);
void nonpreorder(TREE *);
void noninorder(TREE *);

void inorder(TREE *);
void preorder(TREE *);
void postorder(TREE *);

void search(TREE *,int);
void mirror(TREE *);

int count(TREE *);
int nonleafcount(TREE *);
int leafcount(TREE *);

int allsum(TREE *);
int nonleafsum(TREE *);
int leafsum(TREE *);

TREE* maxValueNode(TREE *);
TREE* minValueNode(TREE *);

int height(TREE *);
void level_printing(TREE *);

int main()
{
	TREE *root = NULL, *temp;

	int ch,n,no;

	do
	{
		printf("\n 1: CREATE");
		printf("\n 2: INSERT");
		printf("\n 3: INORDER");
		printf("\n 4: PREORDER");
		printf("\n 5: POSTORDER");
		printf("\n 6: Non Rec. Inorder");
		printf("\n 7: Non Rec. Preorder");
		printf("\n 8: Non Rec. Postorder");
		printf("\n 9: Search Element");
		printf("\n 10: Mirror Tree");
		printf("\n 11: Count Nodes");
		printf("\n 12: Count Leaf Nodes");
		printf("\n 13: Count Non-Leaf Nodes");
		printf("\n 14: Sum Nodes");
		printf("\n 15: Sum Leaf Nodes");
		printf("\n 16: Sum Non-Leaf Nodes");
		printf("\n 17: Delete");
		printf("\n 18: Height");
		printf("\n 19: Max Value");
		printf("\n 20: Min Value");
		printf("\n 21: Levelwise Printing");
		printf("\n 22: EXIT");

		printf("\n Enter your choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: 	printf("\n Enter No. of Nodes : ");
						scanf("%d",&n);
						while(n>0)
						{
							printf("\n Enter Data : ");
							scanf("%d",&no);
							root = create(root,no);
							n--;
						}
						break;
				
			case 2: 	printf("\n Enter Data : ");
						scanf("%d",&n);
						root = insert(root,n);
						break;

			case 3: 	inorder(root);
						break;

			case 4: 	preorder(root);
						break;

			case 5: 	postorder(root);
						break;

			case 6:		noninorder(root);
						break;

			case 7: 	nonpreorder(root);
						break;

			case 8: 	nonpostorder(root);
						break;

			case 9: 	printf("\n Enter element to search : ");
						scanf("%d",&n);

						search(root,n);
						break;

			case 10: 	mirror(root);
						break;

			case 11: 	n = count(root);
				 		printf("\n Total no. of nodes are : %d",n);
				 		break;
			
			case 12: 	n = leafcount(root);
				 		printf("\n Total no. of leaf nodes are : %d",n);
				 		break;
			
			case 13: 	n = nonleafcount(root);
				 		printf("\n Total no. of non-leaf nodes are : %d",n);
				 		break;
			
			case 14: 	n = allsum(root);
				 		printf("\n Sum of nodes is : %d",n);
				 		break;
			
			case 15: 	n = leafsum(root);
				 		printf("\n Sum of leaf nodes is : %d",n);
				 		break;
			
			case 16: 	n = nonleafsum(root);
				 		printf("\n Sum of non-leaf nodes is : %d",n);
				 		break;
			
			case 17: 	printf("\n Enter Data to Delete : ");
				 		scanf("%d",&n);
				 		deleteNode(root, n);
				 		break;
			
			case 18: 	n = height(root);
						printf("\n Height of Tree is : %d",n);
				 		break;
			
			case 19: 	temp = maxValueNode(root);
						printf("\n Max Value of Tree is : %d",temp->data);
				 		break;
			
			case 20: 	temp = minValueNode(root);
						printf("\n Min Value of Tree is : %d",temp->data);
				 		break;
			
			case 21: 	level_printing(root);
				 		break;
						 		 	
			case 22: 	exit(0);
		}
	}while(1);
	
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
		temp->left = insert(temp->left,no);
	}
	else if(no > temp->data)
	{
		temp->right = insert(temp->right,no);
	}

	return temp;
}

TREE* insert(TREE *temp,int no)
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
		temp->left = insert(temp->left,no);
	}
	else if(no > temp->data)
	{
		temp->right = insert(temp->right,no);
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

void postorder(TREE *temp)
{
	if(temp !=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf(" %d ",temp->data);
	}
}

TREE* maxValueNode(TREE *temp)
{
    while (temp && temp->right!=NULL)
    {
    	temp = temp->right;
    }
 
    return temp;
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

void noninorder(TREE *temp)
{
	int top = -1;

	TREE *stack[50];

	while(1)
	{
		while(temp != NULL)
		{
			stack[++top] = temp;
			temp = temp->left;
		}

		if(top != -1)
		{
			temp = stack[top--];
			printf(" %d ",temp->data);
			temp=temp->right;
		}
		else
		{
			break;
		}
	}
}

void  nonpreorder(TREE *temp)
{
	int top = -1;

	TREE *stack[50];

	while(1)
	{
		while(temp != NULL)
		{
			printf(" %d ",temp->data);

			if(temp->right != NULL)
			{
				stack[++top] = temp->right;
			}

			temp = temp->left;
		}

		if(top != -1)
		{
			temp = stack[top--];
		}
		else
		{
			break;
		}
	}
}

void nonpostorder(TREE *temp)
{
	/* int top = -1;

	struct tree *stack[50];

	while(1)
	{
		while(temp != NULL)
		{
			stack[++top] = temp;
			temp = temp->left;
		}

		if(top==-1)
		{
			break;
		}
		else
		{
			temp = stack[top--];

			if(temp->flag==0)
			{
				printf(" %d ",temp->data);
				temp=NULL;
			}
			else
			{
				temp->flag=0;
				stack[++top]=temp;
				temp=temp->right;
			}
		}

	} */
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

void mirror(TREE *temp)
{
	TREE *t;

	if(temp!=NULL)
	{
		mirror(temp->left);
		mirror(temp->right);

		t = temp->left;
		temp->left = temp->right;
		temp->right = t;
	}
}

int count(TREE *temp)
{
	static int cnt=0;

	if(temp!=NULL)
	{
		cnt++;
		count(temp->left);
		count(temp->right);
	}

	return(cnt);
}

int nonleafcount(TREE *temp)
{
	static int cnt=0;

	if(temp!=NULL)
	{
		if(temp->left!=NULL || temp->right!=NULL)
		{
			cnt++;
		}

		nonleafcount(temp->left);
		nonleafcount(temp->right);
	}

	return(cnt);
}

int leafcount(TREE *temp)
{
	static int cnt=0;

	if(temp!=NULL)
	{
		if(temp->left==NULL && temp->right==NULL)
		{
			cnt++;
		}

		leafcount(temp->left);
		leafcount(temp->right);
	}

	return(cnt);
}

int allsum(TREE *temp)
{
	static int sum=0;

	if(temp!=NULL)
	{
		sum=sum+temp->data;
		allsum(temp->left);
		allsum(temp->right);
	}

	return(sum);
}

int nonleafsum(TREE *temp)
{
	static int sum=0;

	if(temp!=NULL)
	{
		if(temp->left!=NULL || temp->right!=NULL)
		{
			sum=sum+temp->data;
		}

		nonleafsum(temp->left);
		nonleafsum(temp->right);
	}

	return(sum);
}

int leafsum(TREE *temp)
{
	static int sum=0;

	if(temp!=NULL)
	{
		if(temp->left==NULL && temp->right==NULL)
		{
			sum=sum+temp->data;
		}

		leafsum(temp->left);
		leafsum(temp->right);
	}

	return(sum);
}

int height(TREE *temp)
{
	int lheight, rheight;
	
    if (temp == NULL)
    {
	    return 0;
	}
    else 
	{
        lheight = height(temp->left);
        rheight = height(temp->right);
 
        if (lheight > rheight) 
		{
            return (lheight + 1);
        }
        else 
		{
            return (rheight + 1);
        }
    }
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
    	CurrentLevel(temp -> left, level - 1);
    	CurrentLevel(temp -> right, level - 1);
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
