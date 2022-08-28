// 17. Write a C program to implement preorder, inorder and postorder traversal without recursion.

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};
