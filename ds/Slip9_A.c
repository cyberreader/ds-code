#include<stdio.h>
#include<math.h>

#define MAX 100

void push(double);
double pop();

double eval(double,char,double);

double stack[MAX];
int top = -1;

int main()
{
	char post[MAX],ch;
	int i;
	double n1,n2,res,val;

	printf("Enter the postfix expression : ");
	scanf("%s",&post);

	for(i=0;post[i]!='\0';i++)
	{
		ch=post[i];

		if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='^' || ch=='$')
		{
			n2=pop();
			n1=pop();

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

		case '%': return((int)n1 % (int)n2);

		case '^':
		case '$': return(pow(n1,n2));
	}
}
