// 22. Write a C program to implement a queue using linked list.

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

int isEmpty(struct node *front, struct node *rear)
{
	if(front == NULL)
		return 1;
	else
		return 0;
}

void enqueue(struct node **front, struct node **rear, int data)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = data;
	if(*front == NULL)
	{
		*front = ptr;
		*rear = ptr;
		(*front)->next = NULL;
		(*rear)->next = NULL;
	}
	else
	{
		(*rear)->next = ptr;
		*rear = ptr;
		(*rear)->next = NULL;
	}
}

void dequeue(struct node **front, struct node **rear)
{
	if(*front == NULL)
		printf("\nQueue is empty");
	else if(*front == *rear)
	{
		*front = NULL;
		*rear = NULL;
	}
	else
	{
		struct node *temp = *front;
		*front = (*front)->next;
		free(temp);
	}
}

void display(struct node *front, struct node *rear)
{
	if(front == NULL)
		printf("\nQueue is empty");
	else
	{
		struct node *temp = front;
		printf("\nThe elements are: ");
		while(temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
	}
}

int main()
{
	struct node *front = NULL;
	struct node *rear = NULL;
	enqueue(&front, &rear, 1);
	enqueue(&front, &rear, 2);
	enqueue(&front, &rear, 3);
	enqueue(&front, &rear, 4);
	enqueue(&front, &rear, 5);
	display(front, rear);
	dequeue(&front, &rear);
	display(front, rear);
	dequeue(&front, &rear);
	display(front, rear);
	return 0;
}
