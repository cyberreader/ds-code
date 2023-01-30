/* Prefix Evaluation */

#include<stdio.h>
#include<math.h>
#include<string.h>

#define MAX 100

void push(double);
double pop();

double eval(double,char,double);

double stack[MAX];
int top = -1;

int main()
{
	char pre[MAX],ch;

	int i;
	double n1,n2,res,val;

	printf("Enter the prefix expression : ");
	scanf("%s",pre);

	strrev(pre);

	for(i=0;pre[i]!='\0';i++)
	{
		ch=pre[i];

		if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='^' || ch=='$')
		{
			n1=pop();
			n2=pop();

			res=eval(n1,ch,n2);

			push(res);
		}
		else
		{
			printf("\n Enter value of %c : ",ch);
			scanf("%lf",&val);

			push(val);
		}
	}

	printf("\n\n Ans. is : %.2lf",pop());

	return 0;
}

void push(double val)
{
	stack[++top] = val;
}

double pop()
{
	return(stack[top--]);
}

double eval(double n1,char op,double n2)
{
	switch(op)
	{
		case '+': return(n1+n2);

		case '-': return(n1-n2);

		case '*': return(n1*n2);

		case '/': return(n1/n2);

		case '%': return((int)n1%(int)n2);

		case '^':
		case '$': return(pow(n1,n2));
	}
}
