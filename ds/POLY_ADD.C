#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 10

typedef struct
{
	int coeff;
	int exp;
}POLY;

int readPoly(POLY[]);
void displayPoly(POLY[],int);
void sortPoly(POLY[],int);
void addPoly(POLY[],POLY[],int,int);

int main()
{
	POLY p1[MAX], p2[MAX];

	int n1,n2,ch;

	do
	{
		printf("\n 1. READ POLY 1");
		printf("\n 2. DISPLAY POLY 1");
		printf("\n 3. READ POLY 2");
		printf("\n 4. DISPLAY POLY 2");
		printf("\n 5. ADD TWO POLY");
		printf("\n 6. EXIT");

		printf("\n ENTER YOUR CHOICE : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:	n1 = readPoly(p1);
				sortPoly(p1,n1);
				break;

			case 2: displayPoly(p1,n1);
				break;

			case 3: n2 = readPoly(p2);
				sortPoly(p2,n2);
				break;

			case 4: displayPoly(p2,n2);
				break;

			case 5:	addPoly(p1,p2,n1,n2);
				break;

			case 6: exit(0);

			default: printf("\n\tWRONG CHOICE....");
		}
	}while(1);

	return 0;
}

int readPoly(POLY p[])
{
	int n,i,j;

	printf("\n ENTER THE NOS OF TERMS : ");
	scanf("%d",&n);

	printf("\n ENTER THE POLYNOMIAL TERMS : ");

	for(i=0;i<n;i++)
	{
		printf("\n Coeff : ");
		scanf("%d",&p[i].coeff);

		printf("\n Exp : ");
		scanf("%d",&p[i].exp);
	}

	return(n);
}

void displayPoly(POLY p[],int n)
{
	int i;

	printf("\n\n Poly : ");

	for(i=0;i<n;i++)
	{
		if(i != 0)
		{
			if(p[i].coeff >= 0)
			{
				printf("+");
			}
			else
			{
				printf("-");
			}
		}
		
		if(p[i].exp==0)
		{
			printf(" %d ",abs(p[i].coeff));
		}
		else if(p[i].exp==1)
		{
			printf(" %dx ",abs(p[i].coeff));
		}
		else if(p[i].coeff==1)
		{
			printf(" x^%d ",p[i].exp);
		}
		else
		{
			printf(" %dx^%d ",abs(p[i].coeff),p[i].exp);
		}
	}
}

void sortPoly(POLY p[],int n)
{
	int i,j;
	POLY temp;

	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].exp < p[j].exp)
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}

void addPoly(POLY p1[],POLY p2[],int n1,int n2)
{
	POLY p3[MAX];
	int i=0,j=0,k=0;

	while(i<n1 && j<n2)
	{
		if(p1[i].exp > p2[j].exp)
		{
			p3[k] = p1[i];
			i++;
			k++;
		}
		else if(p1[i].exp < p2[j].exp)
		{
			p3[k] = p2[j];
			j++;
			k++;
		}
		else
		{
			p3[k].coeff = p1[i].coeff + p2[j].coeff;
			p3[k].exp = p1[i].exp;

			i++;
			j++;
			k++;
		}
	}

	while(i < n1)
	{
		p3[k] = p1[i];
		i++;
		k++;
	}

	while(j < n2)
	{
		p3[k] = p2[j];
		j++;
		k++;
	}

	displayPoly(p3,k);
}
