// 19. Write a C program to find the scenarios in a linked list which leads to segmentation error.

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void insert(struct node **head, int data)
{
	//(*head)->data = data;
	(*head)->next = *head;
}

int main()
{
	struct node *head = NULL;
	insert(&head, 5);
	return 0;
}
