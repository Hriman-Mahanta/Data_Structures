// 17. Write a C program to implement preorder, inorder and postorder traversal without recursion.

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void iterativePreorder(TreeNode root)
{
	if(root == NULL)
		return;
	Stack<TreeNode> treeStack;
	TreeNode currNode = root;
	TreeNode prevNode = NULL;
	while(treeStack.empty() == false || currNode != NULL)
	{
		if(currNode != NULL)
		{
			process(currNode->data);
			treeStack.push(currNode);
			currNode = currNode->left;
		}
		else
		{
			prevNode = treeStack.pop();
			currNode = prevNode->right;
		}
	}
}

void iterativeInorder(TreeNode root)
{
	if(root == NULL)
		return;
	Stack<TreeNode> treeStack;
	TreeNode currNode = root;
	while(treeStack.empty() == false || currNode != NULL)
	{
		if(currNode != NULL)
		{
			treeStack.push(currNode);
			currNode = currNode->left;
		}
		else
		{
			currNode = treeStack.pop();
			process(currNode->data);
			currNode = currNode->right;
		}
	}
}

void iterativePostorder(TreeNode root)
{
	if(root == NULL)
		return;
	Stack<TreeNode> mainStack;
	Stack<TreeNode> rightChildStack;
	TreeNode currNode = root;
	while(!mainStack.empty() || currNode != NULL)
	{
		if(currNode != NULL)
		{
			if(currNode->right != NULL)
				rightChildStack.push(currNode->right)
			mainStack.push(currNode)
			currNode = currNode->left;
		}
		else
		{
			currNode = mainStack.top()
			if(!rightChildStack.isEmpty() && currNode->right == rightChildStack.top())
				currNode = rightChildStack.pop();
			else
			{
				process(currNode->data);
				mainStack.pop();
				currNode = NULL;
			}
		}
	}
}
