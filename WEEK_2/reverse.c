#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>

void createnode();
void display();
void reverse();

struct node
{
    int data;               
    struct node *next;
};

typedef struct node node;

node *head=NULL;

int main()
{
   int n,x,i;
   char y;
   
   printf("enter the number of node in linklist\t");
   scanf("%d",&n);
   for(i=0;i<n;i++)

   {
       createnode();            
   }

   printf("before reverse\n");
   display();                   
   reverse();                   
   printf("\nafter reverse\n");
   display();
}

void createnode()
{
    node *temp;         
    temp=(node*) malloc(sizeof(node));      
    if (temp==NULL)                         
    {
        printf("memory is full");
        exit(0);
    }
    
    printf("enter the data\n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    
    if(head==NULL)              
        head=temp;
    else
    {
        node *q=head;
        while(q->next!=NULL)       
        {
            q=q->next;
        }
        q->next=temp;
        temp=NULL;
        q=NULL;
    }
}

void display()
{
    node *q;
    q=head;
    while(q)
    {
        printf("%d->",q->data);
        q=q->next;              
    }
    q=NULL;
}

void reverse()
{
    node *p=NULL, *q=NULL, *r=head;
    while(r)
    {
        q=r->next;
        r->next=p;      
        p=r;
        r=q;
    }
    head=p;
}
