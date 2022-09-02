// 26. Write a C program to display a BST using graphvine software.

#include<stdio.h>
#include<stdlib.h>

struct bstNode
{
	int key;
	int size;
	struct bstNode *leftChild;
	struct bstNode *rightChild;
};

typedef struct bstNode bstNode;
typedef struct bstNode *bstNodePtr;

// Function to create a root of the BST
void createBST(bstNodePtr *root)
{
	*root = NULL;
}


// Function to allocate memory to a node and return its pointer
bstNodePtr getTreeNode()
{
	bstNodePtr root = (bstNodePtr)malloc(sizeof(bstNode));
	return root;
}

// Function to insert a node into the BST
int bstInsert(bstNodePtr *root, int data)
{
	if(*root == NULL)
	{
		*root = getTreeNode();
		(*root)->key = data;
		(*root)->leftChild = NULL;
		(*root)->rightChild = NULL;
	}
	else if(data < (*root)->key)
	{
		(*root)->size++;
		bstInsert(&((*root)->leftChild), data);
	}
	else if(data > (*root)->key)
	{
		(*root)->size++;
		bstInsert(&((*root)->rightChild), data);
	}
	else
	{
		printf("\nElement already present in the BST");
	}
	return 0;
}

void generateGraph(bstNodePtr root, FILE *fp)
{
    if (root != NULL)
    {
    	//fprintf(fp, "%d[label=\"key: %d, size: %d\"];\n", root->key, root->key, root->size); 
        if(root->leftChild != NULL)
        {
            fprintf(fp, "%d -> %d [color = red];\n", root->key, root->leftChild->key);
            generateGraph(root->leftChild, fp);
        }
        if(root->rightChild != NULL)
        {
            fprintf(fp, "%d -> %d ;\n", root->key, root->rightChild->key);
            generateGraph(root->rightChild, fp);
        }
    }
}


int displayBST(bstNodePtr root, char* filename)
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

int main()
{
	struct bstNode *root = NULL;
	bstInsert(&root, 5);
	bstInsert(&root, 9);
	bstInsert(&root, 12);
	bstInsert(&root, 2);
	bstInsert(&root, 7);
	displayBST(root, "graph.dot");
	system("dot -Tpng graph.dot -o graph.png");
	return 0;
}


