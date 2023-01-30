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
            
            head->prev = last;
            last->next = head;

            n--;
     }     
}

void display()
{
     printf("\n Forward List is : %d ",head->data);
     for(temp=head->next;temp!=head;temp=temp->next)
     {
            printf(" %d ",temp->data);
     }
     
     printf("\n Backward List is : ");
     for(temp=head;temp->next!=head;temp=temp->next);
     
     for(;temp!=head;temp=temp->prev)
     {
            printf(" %d ",temp->data);
     }
     printf(" %d",temp->data);
}

int main()
{
     create();
     display();
     
     return 0;
}
