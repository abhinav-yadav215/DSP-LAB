#include <stdio.h>
 
int A[10], top=-1; 					
int sizeofA = sizeof(A)/sizeof(A[0]); 
 
void Push(int data);
int Pop();
void PrintStack();
int IsEmpty();
 
int main()
{
	Push(10);
	Push(20);
	Push(30);
	Push(40);
	Pop(); 			
	Pop(); 			
	
	PrintStack(); 	
 
return 0;
}
 

int IsEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

void Push(int data)
{
	if(IsEmpty())
		top = 0;
	else if( top == sizeofA )
		printf("\n Stack is Full \n");
	else
		top++;
	
	A[top] = data;
}
 
int Pop()
{
	if(IsEmpty())
		printf("\n Stack is Empty \n");
	else
		top--;
	
	return A[top-1];
}

void PrintStack()
{
	int i=0;
	for(i=0;i<=top;i++)
		printf(" %d",A[i]);
}
                                                      


