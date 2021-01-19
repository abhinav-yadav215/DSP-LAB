#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int data;
	struct Node *link;
}node;
 
int NoOfNodes=0;		
 
node *head=NULL;		
 

void Push(int data);
int Pop();
void PrintStack(node *);
 

int main()
{
	Push(10);
	Push(20);
	Push(30);
	Push(40);
	
	Pop(); 		
	Pop(); 		
	
	PrintStack(head); 
	
	return 0;
}
 

void Push(int data)
{

	NoOfNodes++;
	node *temp = (node*)calloc(1,sizeof(node));
	temp->data = data;
	temp->link = NULL;
	

	if(!head)
	{
		head = temp;
		return;
	}
 

	node *traverse=head;
	while(traverse->link)
		traverse = traverse->link;
	
	traverse->link = temp;
}
 

int Pop()
{
	node *traverse = head;
	int i;
	for(i=0;i<NoOfNodes-2;i++)
		traverse = traverse->link;
	
	node *Delete = traverse->link;
	traverse->link = NULL;
	int data = Delete->data;
	free(Delete);
	NoOfNodes--;
	
	return data;
}
 

void PrintStack(node *p)
{
	printf(" %d",p->data);
	if(!p->link)return;
	PrintStack(p->link);
}

