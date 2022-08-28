// 23. Write a C program to implement a circular queue using circular linked list.

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void enqueue(struct node **front, struct node **rear, int data)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = data;
	if(*front == NULL)
	{
		*front = ptr;
		*rear = ptr;
		(*rear)->next = *front;
	}
	else
	{
		(*rear)->next = ptr;
		*rear = ptr;
		(*rear)->next = *front;
	}
}

void dequeue(struct node **front, struct node **rear)
{
	if(*front == NULL)
	{
		printf("\nQueue is empty");
	}
	else if(*front == *rear)
	{
		*front = NULL;
		*rear = NULL;
	}
	else
	{
		struct node *temp = *front;
		*front = (*front)->next;
		(*rear)->next = *front;
		free(temp);
	}
}

void display(struct node *front, struct node *rear)
{
	if(front == NULL)
	{
		printf("\nQueue is empty");
	}
	else
	{
		struct node *temp = front;
		printf("\nThe elements are: ");
		while(temp->next != front)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("%d ", temp->data);
	}
}

int main()
{
	struct node *front = NULL;
	struct node *rear = NULL;
	enqueue(&front, &rear, 10);
	enqueue(&front, &rear, 11);
	enqueue(&front, &rear, 12);
	enqueue(&front, &rear, 13);
	enqueue(&front, &rear, 14);
	display(front, rear);
	dequeue(&front, &rear);
	display(front, rear);
	dequeue(&front, &rear);
	display(front, rear);
	dequeue(&front, &rear);
	display(front, rear);
	return 0;
}
