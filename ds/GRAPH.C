#include<stdio.h>
#include<stdlib.h>

void create(int g[][10],int n)
{
	int i,j;
	printf("\n Enter the adjacency matrix of the graph : ");
	for(i=0;i<n;i++)
	{
		printf("\n From %c = ",i+65);

		for(j=0;j<n;j++)
		{
			printf("\n\t %c = ",j+65);
			scanf("%d",&g[i][j]);
		}
	}
}

void display_adj_mat(int g[][10],int n)
{
	int i,j;

	printf("\n  ");
	for(i=0;i<n;i++)
	{
		printf(" %c ",i+65);
	}
	
	for(i=0;i<n;i++)
	{
		printf("\n %c",i+65);
		
		for(j=0;j<n;j++)
		{
			printf(" %d ",g[i][j]);
		}
	}
}

void display_adj_list(int g[][10],int n)
{
	int i,j;

	for(i=0;i<n;i++)
	{
		printf("\n %c",i+65);

		for(j=0;j<n;j++)
		{
			if(g[i][j]==1)
			{
				printf("->%c",j+65);
			}
		}

		printf("->NULL");
	}
}

void degree(int g[][10],int n)
{
	int i,j,idrg,odrg;
	
	for(i=0;i<n;i++)
	{
		idrg=0;
		odrg=0;

		for(j=0;j<n;j++)
		{
			if(g[i][j]==1)
			{
				odrg++;
			}
			if(g[j][i]==1)
			{
			      idrg++;
			}
		}

		printf("\n vertex:%c\t  indegree:%d\t  outdegree:%d\t total degree:%d",i+65,idrg,odrg,idrg+odrg);
	}
}

void direction(int g[][10],int n)
{
	int i,j;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(g[i][j]!=g[j][i])
			{
				printf("\n Unidirectional");
				return;
			}
		}
	}

	printf("\n Bidirectional");
}

int main()
{
	int g[10][10],n,ch;

	do
	{
		printf("\n 1. Create Adj. Matrix");
		printf("\n 2. Display Adj. Matrix");
		printf("\n 3. Display Adj. List");
		printf("\n 4. Count Degree");
		printf("\n 5. Direction");
		printf("\n 6. Exit");
		
		printf("\n Enter Choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:	printf("\n Enter the No. of nodes : ");
					scanf("%d",&n);
					create(g,n);
					break;
					
			case 2:	display_adj_mat(g,n);
					break;
			case 3:	display_adj_list(g,n);
					break;
			case 4:	degree(g,n);
					break;
			case 5:	direction(g,n);
					break;
			case 6:	exit(0);
			
			default:printf("\n Invalid Choice");
		}
	}while(1);

	return 0;
}
