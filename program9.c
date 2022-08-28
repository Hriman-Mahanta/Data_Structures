// 9. Write a C program to implement a stack permutation.

#include<stdio.h>
#define SIZE 50

int isFull(int A[], int top)
{
	if(top == SIZE-1)
		return 1;
	else
		return 0;
}

int isEmpty(int A[], int top)
{
	if(top == -1)
		return 1;
	else
		return 0;
}

void push(int A[], int *top, int data)
{
	if(isFull(A, *top))
	{
		printf("\nStack overflow");
	}
	else
	{
		*top = *top + 1;
		A[*top] = data;
	}
}

void pop(int A[], int *top)
{
	if(isEmpty(A, *top))
	{
		printf("\nStack underflow");
	}
	else
	{
		*top = *top - 1;
	}
}

int peek(int A[], int top)
{
	if(top == -1)
	{
		printf("\nStack underflow");
		return -1;
	}
	else
	{
		return A[top];
	}
}

int stackperm(int ip[], int op[], int n)
{
	int top = -1;
	int stack[SIZE];
	int j = 0;
	for(int i=0; i<n; i++)
	{
		push(stack, &top, ip[i]);
		while(!isEmpty(stack, top) && (stack[top] == op[j]))
		{
			pop(stack, &top);
			j++;
		}
	}
	if(isEmpty(stack, top))
		return 1;
	else
		return 0;
}

int main()
{
	int input[5] = {4, 5, 6, 7, 8};
	int output[5] = {8, 7, 6, 5, 4};
	if(stackperm(input, output, 5))
		printf("\nValid stack permutation");
	else
		printf("\nInvalid stack permutation");
	return 0;
}
	
