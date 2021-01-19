#include<stdio.h> 
#include<math.h>
#include<stdbool.h>
#include<stdlib.h>
bool Prime(int x) 
{ 
	if (x<= 1) 
		return false; 
	if (x<= 3) 
		return true; 
		
		
	if (x % 2 == 0 || x % 3 == 0) 
		return false; 
	int i;
	for (i = 5; i * i <= x; i = i + 6) 
		if (x % i == 0 || x% (i + 2) == 0) 
			return false; 

	return true; 
} 

bool checkCircularprime(int N) 
{ 
	int count = 0, temp = N; 
	while (temp) { 
		count++; 
		temp /= 10; 
	} 

	int num = N; 
	while (Prime(num)) { 
		int rem = num % 10; 
		int div = num / 10; 
		num = (pow(10, count - 1)) * rem + div; 

		if (num == N) 
			return true; 
	} 

	return false; 
} 

int main() 
{ 
	int N;
	scanf("%d",&N);
	
	if(N<=0)
	printf("-1");
	
	else if(checkCircularprime(N)) 
		printf("1");
	else
		printf("0");
    
	return 0; 
}
