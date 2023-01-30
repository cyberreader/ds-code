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
float evalPoly(POLY[],int);

int main()
{
	POLY p[MAX];
	int n,ch;
	float ans=0;
	
	do
	{
		printf("\n 1. READ POLY");
		printf("\n 2. DISPLAY POLY");
		printf("\n 3. EVALUATE POLY");
		printf("\n 4. EXIT");

		printf("\n ENTER YOUR CHOICE : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:	n = readPoly(p);
				sortPoly(p,n);
				break;

			case 2: displayPoly(p,n);
				break;

			case 3: ans = evalPoly(p,n);
				printf("\n Sum of the polynomial is : %.2f", ans);
				break;

			case 4: exit(0);

			default: printf("\n\t INVALID CHOICE....");
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

float evalPoly(POLY p[],int n)
{
	POLY p3[MAX];
	int i;
	float x,ans=0;

	printf("\n Enter the value of x : ");
    scanf("%f",&x);
    
    for (i=0;i<n;i++)
    {
        ans = ans + p[i].coeff * pow(x, p[i].exp);
    }
    
    return ans;
}
