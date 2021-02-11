#include<stdio.h> 
#define V 6
#define INF 99999 
void printSolution(int dist[][V]); 
void floydWarshall (int graph[][V]) 
{ 
	int dist[V][V], i, j, k; 
	for (i = 0; i < V; i++) 
		for (j = 0; j < V; j++) 
			dist[i][j] = graph[i][j]; 
	for (k = 0; k < V; k++) 
	{ 
		for (i = 0; i < V; i++) 
		{ 
			for (j = 0; j < V; j++) 
			{ 
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		} 
	} 
	printSolution(dist); 
} 
void printSolution(int dist[][V]) 
{ 
	printf ("The following matrix shows the shortest distances"
			" between every pair of vertices \n"); 
		int i;
	for (i = 0; i < V; i++) 
	{ 
		int j;
		for (j = 0; j < V; j++) 
		{ 
			if (dist[i][j] == INF) 
				printf("%7s", "INF"); 
			else
				printf ("%7d", dist[i][j]); 
		} 
		printf("\n"); 
	} 
} 
int main() 
{ 
	int graph[V][V] = { {0, 5, 6,INF,INF,INF}, 
						{5, 0, 8,3,4,INF}, 
						{6,8,INF,INF,6,INF}, 
						{INF,3,INF,0,3,7},
						{INF,4,6,3,0,7},
						{INF,INF,INF,7,7,0}
					}; 
	floydWarshall(graph); 
	return 0; 
} 

