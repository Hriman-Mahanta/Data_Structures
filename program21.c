// 21. Write a C program to implement a stack using linked list.

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

int isEmpty(struct node *top)
{
	if(top == NULL)
		return 1;
	else
		return 0;
}

void push(struct node **top, int data)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = data;
	if(*top == NULL)
	{
		*top = ptr;
		return;
	}
	ptr->next = *top;
	*top = ptr;
}

void pop(struct node **top)
{
	if(*top == NULL)
	{
		printf("\nStack is empty");
		return;
	}
	struct node *temp = *top;
	*top = (*top)->next;
	free(temp);
}

void display(struct node *top)
{
	struct node *temp = top;
	if(top == NULL)
	{
		printf("\nStack is empty");
		return;
	}
	printf("\nThe elements are: ");
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

int main()
{
	struct node *top = NULL;
	push(&top, 5);
	push(&top, 6);
	push(&top, 7);
	push(&top, 8);
	push(&top, 9);
	display(top);
	pop(&top);
	display(top);
	pop(&top);
	display(top);
	return 0;
}
