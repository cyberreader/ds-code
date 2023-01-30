#include<stdio.h>
#include<math.h>
#include<malloc.h>

typedef struct stack
{
	double data;
	struct stack *next;
}STACK;

STACK *top, *temp;

void init()
{
	top = NULL;
}

void push(double ch)
{
	temp = (STACK*) malloc(sizeof(STACK));
	
	temp->data = ch;

	temp->next = top;
	top = temp;
}

double pop()
{
	double ch;
	
	if(top==NULL)
	{
		return 0;
	}
	
	temp = top;
	ch = temp->data;
	top = top->next;
	free(temp);
	return ch;
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

int main()
{
	char post[100],ch;
	int i;
	double n1,n2,res,val;

	printf("Enter the postfix expression : ");
	scanf("%s",post);

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

