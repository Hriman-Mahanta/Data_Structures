// 34. Write a C program to find whether a graph is Eulerian or not. Use adjacency matrix representation.

#include<stdio.h>

int main()
{
	int n;
	int A[10][10];
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
	int deg[10];
	for(int i=0; i<n; i++)
	{	
		deg[i] = 0;
		for(int j=0; j<n; j++)
		{
			deg[i] += A[i][j];
		}
	}
	int oddcount = 0;
	for(int i=0; i<n; i++)
	{
		if (deg[i]%2 != 0)
			oddcount ++;
	}
	if(oddcount > 0)
		printf("\nfalse");
	else
		printf("\ntrue");
	return 0;
}
