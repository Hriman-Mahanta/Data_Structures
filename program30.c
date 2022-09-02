// 30. Write a C program to find the height of a Binary Search Tree.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
	int height;
};

int bstInsert(struct node **root, int data)
{
	if(*root == NULL)
	{
		*root = (struct node*)malloc(sizeof(struct node));
		(*root)->data = data;
		(*root)->left = NULL;
		(*root)->right = NULL;
		(*root)->height = 0;
	}
	else if(data < (*root)->data)
	{
		bstInsert(&((*root)->left), data);
	}
	else if(data > (*root)->data)
	{
		bstInsert(&((*root)->right), data);
	}
	else
	{
		printf("\nElement already present in the BST");
	}
	*(root)->height = 1 + max(*(root)->left->height, *(root)->right->height);
	return 0;
}

void generateGraph(struct node *root, FILE *fp)
{
    if (root != NULL)
    {
    	fprintf(fp, "%d[label=\"key: %d, height: %d\"];\n", root->data, root->data, root->height); 
        if(root->left != NULL)
        {
            fprintf(fp, "%d -> %d [color = red];\n", root->data, root->left->data);
            generateGraph(root->left, fp);
        }
        if(root->right != NULL)
        {
            fprintf(fp, "%d -> %d ;\n", root->data, root->right->data);
            generateGraph(root->right, fp);
        }
    }
}


int displayBST(struct node *root, char* filename)
{
	FILE *fp;
	fp = fopen(filename, "w+");
	if (fp == NULL)
        	return -1;
   	fprintf(fp, "digraph g{\n");
   	generateGraph(root, fp);
   	fprintf(fp,"}\n");
	fclose(fp);

    	return 0;
}

int max(int a, int b)
{
	return a>b ? a:b;
}
int findHeight(struct node *root)
{
	if(root == NULL)
		return -1;
	return max(findHeight(root->left), findHeight(root->right)) + 1;
}

int main()
{
	struct node *root = NULL;
	bstInsert(&root, 5);
	bstInsert(&root, 6);
	bstInsert(&root, 1);
	bstInsert(&root, 7);
	bstInsert(&root, 2);
	bstInsert(&root, 8);
	bstInsert(&root, 9);
	int height = findHeight(root);
	printf("\nThe height is: %d", height);
	displayBST(root, "graph.dot");
	system("dot -Tpng graph.dot -o graph.png");
	return 0;
}
