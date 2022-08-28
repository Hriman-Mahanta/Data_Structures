// 6. Write a C program to implement a stack using array.

#include<stdio.h>
#define SIZE 50

int isempty(int A[], int top)
{
	if(top == -1)
		return 1;
	else
		return 0;
}

int isfull(int A[], int top)
{
	if(top == SIZE-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(int A[], int *top, int data)
{
	if(!isfull(A, *top))
	{
		*top = *top + 1;
		A[*top] = data;
	}
	else
	{
		printf("Stack is full");
	}
}

int pop(int A[], int *top)
{
	if(!isempty(A, *top))
	{	
		int value = A[*top];
		*top = *top - 1;
		printf("\nPopped element is %d", value);
	}
	else
	{
		printf("Stack is empty");
	}
}

void display(int A[], int top)
{	
	printf("\nThe elements in the stack are:");
	for(int i=0; i<=top; i++)
	{
		printf("%d  ", A[i]);
	}
}

int main()
{
	int A[SIZE], top=-1;
	push(A, &top, 5);
	push(A, &top, 6);
	push(A, &top, 7);
	push(A, &top, 8);
	push(A, &top, 9);
	pop(A, &top);
	pop(A, &top);
	display(A, top);
	push(A, &top, 10);
	display(A, top);
	return 0;
}
	
