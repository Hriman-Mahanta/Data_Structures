// 14. Write a C program to implement a binary search tree.

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

//Create a node
void createNode(struct node **root, int value)
{
	*root = (struct node*)malloc(sizeof(struct node));
	(*root)->data = value;
	(*root)->left = NULL;
	(*root)->right = NULL;
}

//Insert a node
void insert(struct node **root, int value)
{
	if(root == NULL)
		createNode(&(*root), value);
	if(value < (*root)->data)
		insert(&((*root)->left), value);
	else
		insert(&((*root)->right), value);
}

//Find minimum value node
struct node *minValueNode(struct node *root)
{
	struct node *temp = root;
	while(temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp;
}

//Find maximum value node
struct node *maxValueNode(struct node *root)
{
	struct node *temp = root;
	while(temp->right != NULL)
	{
		temp = temp->right;
	}
	return temp;
}

//Delete a node
void deleteNode(struct node **root, int value)
{
	if(*root == NULL)
	{
		printf("\nEmpty linked list");
		return;
	}
	if(value < root->data)
		deleteNode(&((*root)->left), value);
	else if(value > root->data)
		deleteNode(&((*root)->right), value);
	else
	{
		// No children
		if((*root)->left == NULL && (*root)->right == NULL)
		{
			free(*root);
			return;
		}
		// One children
		else if((*root)->left == NULL || (*root)->right == NULL)
		{
			struct node *temp;
			if((*root)->left == NULL)
				temp = (*root)->right;
			else if((*root)->right == NULL)
				temp = (*root)->left;
			
			free(root);
			return temp;				
		}
		// Two childrens
		else
		{
			struct node *temp = minValueNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}
	return root;
}

//Search a node
struct node *searchNode(struct node *root, int value)
{
	while(root != NULL || root->data == value)
	{
		if(value < root->data)
			searchNode(root->left, value);
		else if(value > root->data)
			searchNode(root->right, value);
	}
	return root;
}

int main()
{
	struct node *root;
	root = createNode(20);
    	insertNode(root,5);
    	insertNode(root,1);
    	insertNode(root,15);
    	insertNode(root,9);
    	insertNode(root,7);
    	insertNode(root,12);
    	insertNode(root,30);
    	insertNode(root,25);
    	insertNode(root,40);
    	insertNode(root, 45);
    	insertNode(root, 42);
    	return 0;
}

