#include<stdio.h>
#include<malloc.h>

typedef struct node
{
       int data;
       struct node *prev,*next;
}NODE;

NODE *head=NULL,*last,*temp;

void create()
{
     int n;
     head = NULL;
     
     printf("\n Enter No. of Nodes : ");
     scanf("%d",&n);
     
     while(n>0)
     {
            temp = (NODE*) malloc(sizeof(NODE));
            
            printf("\n Enter Data : ");
            scanf("%d",&temp->data);
            
            temp->prev = NULL;
            temp->next = NULL;
            
            if(head==NULL)
            {
                   head = temp;
            }
            else
            {
                   last->next = temp;
                   temp->prev = last;
            }
            
            last = temp; 
            
            n--;
     }     
}

void display()
{
    printf("\n List is : ");
    for(temp=head;temp!=NULL;temp=temp->next)
    {
     	if(temp->data%2!=0)
     	{
		    printf(" %d ",temp->data);
		}
    }
}

int main()
{
    create();
    display();
     
    return 0;
}
