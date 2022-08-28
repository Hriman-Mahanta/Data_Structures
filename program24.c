// 24. Write a C program to find the kth smallest and kth largest element in a Binary Search Tree.

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
	int lcount;
	int rcount;
};

void newNode(struct node **root, int data)
{
	*root = (struct node *)malloc(sizeof(struct node));
	(*root)->data = data;
	(*root)->left = NULL;
	(*root)->right = NULL;
}

void insert(struct node **root, int data)
{
	if(*root == NULL)
		newNode(&(*root), data);
	else if(data < (*root)->data)
	{
		insert(&((*root)->left), data);
		(*root)->lcount++;
	}
	else
	{
		insert(&((*root)->right), data);
		(*root)->rcount++;
	}
}

struct node *kthSmallest(struct node *root, int k)
{
	if(root == NULL)
		return NULL;
	int count = root->lcount + 1;
	if(count == k)
		return root;
	if(count > k)
		return kthSmallest(root->left, k);
	return kthSmallest(root->right, k-count);
}

struct node *kthLargest(struct node *root, int k)
{
	if(root == NULL)
		return NULL;
	int count = root->rcount + 1;
	if(count == k)
		return root;
	if(count > k)
		return kthLargest(root->right, k);
	return kthLargest(root->left, k-count);
}

int main()
{
	struct node *root = NULL;
	newNode(&root, 5);
	insert(&root, 7);
	insert(&root, 2);
	insert(&root, 9);
	insert(&root, 11);
	insert(&root, 6);
	struct node *res1 = kthSmallest(root, 3);
	struct node *res2 = kthLargest(root, 2);
	if(res1 == NULL)
	{
		printf("\nNumber of nodes is less than k");
	}
	else
	{
		printf("\nKth smallest node is %d", res1->data);
	}
	
	if(res2 == NULL)
	{
		printf("\nNumber of nodes is less than k");
	}
	else
	{
		printf("\nKth largest node is %d", res2->data);
	}
	return 0;
}
