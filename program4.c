// 4. Write a C program to implement a linked list.

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void display(struct node *head)
{
	struct node *ptr = head;
	if (ptr == NULL)
	{
		printf("\nNothing to print");
	}
	else
	{	
		printf("\nThe elements are:"); 
		while(ptr != NULL)
		{
			printf("%d -> ", ptr->data);
			ptr = ptr->next;
		}
	}
}

void search(struct node *head, int data)
{
	struct node *ptr = head;
	int i = 0, flag;
	if(ptr == NULL)
	{
		printf("Empty list");
	}
	else
	{
		while(ptr != NULL)
		{
			if(ptr->data == data)
			{
				printf("\nItem found at position %d", i+1);
				flag = 0;
			}
			i++;
			ptr = ptr->next;
		}
		if (flag == 1)
		{
			printf("Item not found");
		}
	}
}

void insert_at_beg(struct node **head, int data)
{
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = data;
	ptr->next = *head;
	*head = ptr;
}

void insert_at_end(struct node **head, int data)
{
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	struct node *tmp = *head;
		
	ptr->data = data;
	
	if(*head == NULL)
	{
		*head = ptr;
		(*head) -> next = NULL;
		return;
	}
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = ptr;
	ptr->next = NULL;
	return;
}

void delete_at_beg(struct node **head)
{
	struct node *temp = *head;
	if(*head == NULL)
	{
		printf("\nEmpty List");
		return;
	}
	
	*head = (*head)->next;	
	free(temp);
}

void delete_at_end(struct node **head)
{
	if(*head == NULL)
	{
		printf("\nEmpty List");
		return;
	}
	
	if((*head)->next == NULL)
	{
		*head = NULL;
		free(*head);
	}
	
	struct node *temp = *head;
	struct node *prev = NULL;
	while(temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	free(temp);
}


int main()
{
	struct node *head = NULL;
	insert_at_beg(&head, 2);
	insert_at_beg(&head, 3);
	insert_at_beg(&head, 4);
	insert_at_beg(&head, 5);
	display(head);
	insert_at_end(&head, 6);
	insert_at_end(&head, 7);
	insert_at_end(&head, 8);
	insert_at_end(&head, 9);
	display(head);
	delete_at_beg(&head);
	delete_at_end(&head);
	display(head);
	delete_at_beg(&head);
	delete_at_end(&head);
	display(head);
	search(head, 2);
	display(head);
	return 0;
}
	
