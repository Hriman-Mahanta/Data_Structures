// 10. Write a C program to implement a circular linked list using arrays.

#include<stdio.h>
#define SIZE 50

int isFull(int A[], int front, int rear)
{
	if((front == rear + 1) || (front == 0 && rear ==(SIZE - 1)))
		return 1;
	else
		return 0;
}

int isEmpty(int A[], int front, int rear)
{
	if(front == -1)
		return 1;
	else
		return 0;
}

void enqueue(int A[], int *front, int *rear, int data)
{
	if(isFull(A, *front, *rear))
	{
		printf("Queue is full");
	}
	else
	{
		if(*front == -1)
		{
			*front = 0;
		}
		*rear = (*rear+1)%SIZE;
		A[*rear] = data;
	}
}

void dequeue(int A[], int *front, int *rear)
{
	if(isEmpty(A, *front, *rear))
	{
		printf("Queue is empty");
	}
	else
	{
		if(*front == *rear)
			*front = *rear = -1;
		else
			*front = (*front+1)%SIZE;
	}
}

void display(int A[], int front, int rear)
{
	if(isEmpty(A, front, rear))
		printf("Queue is empty");
	else
	{	
		printf("\nThe elements are: ");
		for(int i = front; i != rear+1; i=(i+1)%SIZE)
		{
			printf("%d ", A[i]);
		}
	}
}

int main()
{
	int A[SIZE], front=-1, rear=-1;
	enqueue(A, &front, &rear, 10);
	enqueue(A, &front, &rear, 11);
	enqueue(A, &front, &rear, 12);
	enqueue(A, &front, &rear, 13);
	enqueue(A, &front, &rear, 14);
	display(A, front, rear);
	//dequeue(A, &front, &rear);
	//dequeue(A, &front, &rear);
	//display(A, front, rear);
	return 0;
}
