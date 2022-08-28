// 13. Write a C program to implement inorder, preorder and postorder traversal in a binary tree.

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

//Inorder Traversal
void inorderTraversal(struct node *root)
{
	if(root == NULL)
		return;
	inorderTraversal(root->left);
	printf("%d -> ", root->data);
	inorderTraversal(root->right);
}

//Preorder Traversal
void preorderTraversal(struct node *root)
{
	if(root == NULL)
		return;
	printf("%d -> ", root->data);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

//Postorder Traversal
void postorderTraversal(struct node *root)
{
	if(root == NULL)
		return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%d -> ", root->data);
}

void createNode(struct node **root, int value)
{
	*root = (struct node *)malloc(sizeof(struct node));
	(*root)->data = value;
	(*root)->left = NULL;
	(*root)->right = NULL;
}


int main()
{
	struct node *root = NULL;
	createNode(&root, 1);
	createNode(&(root->left), 9);
	createNode(&(root->right), 11);
	createNode(&(root->left->left), 15);
	createNode(&(root->left->right), 2);
	printf("\nInorder Traversal\n");
	inorderTraversal(root);
	printf("\nPreorder Traversal\n");
	preorderTraversal(root);
	printf("\nPostorder Traversal\n");
	postorderTraversal(root);
	return 0;
}
	
