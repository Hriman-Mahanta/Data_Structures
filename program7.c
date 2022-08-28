// 7. Write a C program to implement a queue using array.

#include<stdio.h>
#define SIZE 50

int isFull(int queue[], int front, int rear)
{
	if(rear == SIZE-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isEmpty(int queue[], int front, int rear)
{
	if(front == -1 && rear == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void enqueue(int queue[], int *front, int *rear, int data)
{
	if (isFull(queue, *front, *rear))
	{
		printf("\nQueue is full");
		return;
	}
	else if(*front == -1 && *rear == -1)
	{
		*front = 0;
		*rear = 0;
	}
	else
	{
		*rear = *rear + 1;
	}
	queue[*rear] = data;
}

void dequeue(int queue[], int *front, int *rear)
{
	if(isEmpty(queue, *front, *rear))
	{
		printf("\nQueue is empty");
	}
	else
	{
		int data = queue[*front];
		*front = *front + 1;
		if(*front >= *rear)
		{
			*front = -1;
			*rear = -1;
		}
		printf("\nDequeued element: %d", data);
	}
}

void display(int queue[], int front, int rear)
{
	if(isEmpty(queue, front, rear))
	{
		printf("\nQueue is empty");
	}
	else
	printf("\nThe elements are: ");
	{
		for(int i=front; i<=rear; i++)
			printf("%d  ", queue[i]);
	}
}

int main()
{
	int A[SIZE], front=-1, rear=-1;
	enqueue(A, &front, &rear, 5);
	enqueue(A, &front, &rear, 4);
	enqueue(A, &front, &rear, 3);
	enqueue(A, &front, &rear, 1);
	display(A, front, rear);
	dequeue(A, &front, &rear);
	display(A, front, rear);
	return 0;

}
