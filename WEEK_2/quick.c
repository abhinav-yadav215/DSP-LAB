#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void swap(int *a, int *b);
void quicksort(int *arr,int strt,int end);
void startnend(int *arr,int n,int end);
void getARRAY(int *arr,int len);

void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return;
}

void quicksort(int *arr,int strt,int end)
{
	int i=0,j=0;
	
	for(i=0;i<=end;i++)
	{
		for(j=i+1;j<=end;j++)
		{
			if(arr[j]<arr[i])
				swap(&arr[i],&arr[j]);
		}
	}
	
	return;
}

void startnend(int *arr,int n,int end)
{
	int sflag,eflag,i=0,c=0;
	while(i<=end)
	{
		if(arr[i]==n&&c==0)
		{
			sflag=i;
			c++;
		}
		if(arr[i]==n&&c!=0)
			eflag=i;
		
		i++;
	}
	if(c==0) printf("\nNo such number is found");	
	if(c!=0) printf("Number Found at index %d and last occurance at index %d", sflag+1,eflag+1);
	return;
}

void getARRAY(int *arr,int len)
{
	int i=0;
	printf("Enter elements to be sorted: \n");
	for(i=0;i<len;i++)
		scanf("%d",arr[i]);
		
	return;
}
		

void main()
{
	int *a,x,i,n=0;
   printf("Enter the No. of elements of the array: ");
   scanf("%d",&n);
   a = (int*)calloc(n, sizeof(int*));
   printf("\n enter elements: ");
   for(i=0;i<n;i++)
	   scanf("%d",&a[i]);
	   
	for(i=0;i<n;i++)
	   printf("%d ",a[i]);
	//getARRAY(arr,n);
	qisort(a,0,n-1);
	printf("\n");
	
	for(i=0;i<n;i++)
	   printf("%d ",a[i]);
	
	printf("enter a num to search: ");
	scanf("%d",&x);
	
	startnend(a,n,n-1);
	return;
}
