// 5. Write a C program to implement a doubly linked list.

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};

void display(struct node *head)
{
	struct node *ptr = head;
	if(head == NULL)
	{
		printf("\nEmpty List");
	}
	
	printf("\nThe elements are:");
	while(ptr != NULL)
	{
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}
}

void search(struct node *head, int data)
{
	int i=0, flag=1;
	struct node *ptr = head;
	while(ptr != NULL)
	{
		if(ptr->data == data)
		{
			printf("Item found at position %d\n", i+1);
			flag = 0;
		}
		i++;
		ptr = ptr->next;
	}
	if(flag == 1)
	{
		printf("Item not found");
	}
}

void insert_at_beg(struct node **head, int data)
{
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	if(*head == NULL)
	{
		*head = ptr;
		(*head)->prev = NULL;
		(*head)->data = data;
		(*head)->next = NULL;
		return;
	}
	ptr->data = data;
	ptr->prev = NULL;
	ptr->next = *head;
	(*head)->prev = ptr;
	*head = ptr;
}

void insert_at_end(struct node **head, int data)
{
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	if(*head == NULL)
	{
		*head = ptr;
		(*head)->prev = NULL;
		(*head)->data = data;
		(*head)->next = NULL;
		return;
	}
	struct node *tmp = *head;
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = ptr;
	ptr->prev = tmp;
	ptr->data = data;
	ptr->next = NULL;
}

void delete_at_beg(struct node **head)
{
	struct node *temp = *head;
	if(*head == NULL)
	{
		printf("\nEmpty List");
		return;
	}
	if((*head)->next == NULL)
	{
		(*head)->prev = NULL;
		(*head)->next = NULL;
		free(*head);
	}
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}

void delete_at_end(struct node **head)
{
	struct node *temp = *head;
	if(*head == NULL)
	{
		printf("\nEmpty List");
		return;
	}
	if((*head)->next == NULL)
	{
		(*head)->prev = NULL;
		(*head)->next = NULL;
		free(*head);
	}
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->prev->next = NULL;
}

int main()
{
	struct node *head = NULL;
	insert_at_beg(&head, 5);
	insert_at_beg(&head, 6);
	insert_at_beg(&head, 7);
	insert_at_beg(&head, 8);
	display(head);
	insert_at_end(&head, 1);
	insert_at_end(&head, 2);
	insert_at_end(&head, 3);
	insert_at_end(&head, 4);
	display(head);
	delete_at_beg(&head);
	delete_at_beg(&head);
	display(head);
	delete_at_end(&head);
	delete_at_end(&head);
	display(head);
	search(head, 5);
	display(head);
	return 0;
}
