// 25. Write a C program to find all the elements in a Binary Search Tree within a range

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void createNode(struct node **root, int data)
{
	*root = (struct node*)malloc(sizeof(struct node));
	(*root)->data = data;
	(*root)->left = NULL;
	(*root)->right = NULL;
}

void insert(struct node **root, int data)
{
	if(*root == NULL)
		createNode(&(*root), data);
	else if(data < (*root)->data)
		insert(&((*root)->left), data);
	else
		insert(&((*root)->right), data);
}
	
void printRange(struct node *root, int k1, int k2)
{
	if (root == NULL)
		return;
	if(k1 < root->data)
		printRange(root->left, k1, k2);
	if(k1 <= root->data && k2 >= root->data)
		printf("%d ", root->data);
	
	printRange(root->right, k1, k2);
}

int main()
{
	struct node *root = NULL;
	int k1=10, k2=25;
	
	createNode(&root, 20);
	insert(&root, 8);
	insert(&root, 22);
	insert(&root, 4);
	insert(&root, 12);
	
	printRange(root, k1, k2);
	return 0;
}	
