// 33. Write a C program to implement an AVL Tree.


#include <stdio.h>
#include <stdlib.h>

// Create Node
struct node 
{
	int key;
	struct node *left;
	struct node *right;
	int height;
	int balance;
};


// Calculate Height
int height(struct node *root) 
{
	if (root == NULL)
	    return -1;
  	return root->height;
}

int max(int a, int b) 
{
	return (a > b) ? a : b;
}

// Create a Node
struct node *newNode(int key) 
{
	struct node *root = (struct node *)malloc(sizeof(struct node));
	root->key = key;
	root->left = NULL;
	root->right = NULL;
	root->height = 0;
	root->balance = 0;
	return (root);
}

// Right Rotate
struct node *rightRotate(struct node *y) 
{
	struct node *x = y->left;
	struct node *temp = x->right;

	x->right = y;
	y->left = temp;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	return x;
}

// Left rotate
struct node *leftRotate(struct node *x) 
{
	struct node *y = x->right;
	struct node *temp = y->left;

	y->left = x;
	x->right = temp;

	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	return y;
}

// Get the balance factor
int getBalance(struct node *root) 
{
	if (root == NULL)
		return 0;
	return height(root->left) - height(root->right);
}

// Insert node
struct node *insertNode(struct node *root, int key) 
{
	// Find the correct position to insertNode the node and insertNode it
	if (root == NULL)
		return (newNode(key));
	if (key < root->key)
		root->left = insertNode(root->left, key);
	else if (key > root->key)
		root->right = insertNode(root->right, key);
	else
		return root;

  	// Update the balance factor of each node and balance the tree
  	root->height = 1 + max(height(root->left), height(root->right));
  	root->balance = getBalance(root);
	int balance = getBalance(root);
	if (balance > 1 && key < root->left->key)
		return rightRotate(root);
	if (balance < -1 && key > root->right->key)
		return leftRotate(root);
	if (balance > 1 && key > root->left->key) 
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if (balance < -1 && key < root->right->key) 
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}

struct node *minNode(struct node *root) 
{
	struct node *current = root;

	while (current->left != NULL)
		current = current->left;
	return current;
}

// Delete a node
struct node *deleteNode(struct node *root, int key) 
{
	// Find the node and delete it
	if (root == NULL)
		return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);

	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	else 
	{
		if ((root->left == NULL) || (root->right == NULL)) 
		{
			struct node *temp = root->left ? root->left : root->right;
			if (temp == NULL) 
			{
				temp = root;
				root = NULL;
      			} 
      			else
				*root = *temp;
      			free(temp);
    		} 
    		else 
    		{
      			struct node *temp = minNode(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
	}
	if (root == NULL)
    		return root;

	// Update the balance factor of each node and balance the tree
	root->height = 1 + max(height(root->left), height(root->right));
	root->balance = getBalance(root);
	int balance = getBalance(root);
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);
	if (balance > 1 && getBalance(root->left) < 0) 
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	if (balance < -1 && getBalance(root->right) > 0) 
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}

// Inorder Traversal
void inorder(struct node *root) 
{
	if (root != NULL) 
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
  	}
}

void generateGraph(struct node *root, FILE *fp)
{
    if (root != NULL)
    {
    	fprintf(fp, "%d[label=\"key: %d, balance: %d, height: %d\"];\n", root->key, root->key, root->balance, root->height); 
        if(root->left != NULL)
        {
            fprintf(fp, "%d -> %d [color = red, style=dotted];\n", root->key, root->left->key);
            generateGraph(root->left, fp);
        }
        if(root->right != NULL)
        {
            fprintf(fp, "%d -> %d ;\n", root->key, root->right->key);
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


int main() 
{
	struct node *root = NULL;
	int flag=1;
	while(flag == 1)
	{
		printf("\n\n\n\n1. Insert an element");
		printf("\n2. Search an element");
		printf("\n3. Find kth largest element");
		printf("\n4. Delete an element");
		printf("\n5. Find minimum element");
		printf("\n6. Display the BST");
		printf("\n7. Quit");
		printf("\n\nEnter your choice: ");
		int choice;
		int ele, k;
		struct node *res;
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the element to be inserted: ");
				scanf("%d", &ele);
				root = insertNode(root, ele);
				break;
			case 2:
				printf("\nEnter the element to be searched: ");
				scanf("%d", &ele);
				//res = bstSearch(root, ele);
				//if(res != NULL)
				//	printf("\nThe element is present in the BST");
				//else
				//	printf("\nThe element is not present in the BST");
				break;
			case 3:
				printf("\nEnter the value of k: ");
				scanf("%d", &k);
				//res = kthElement(root, k);
				//printf("\nThe kth largest element is %d", res->key);
				break;
			case 4:
				printf("\nEnter the element to be deleted: ");
				scanf("%d", &ele);
				root = deleteNode(root, ele);
				break;
			case 5:
				//res = minNode(root);
				//printf("\nThe minimum element is %d", res->key);
				break;
			case 6:
				printf("\nThe inorder traversal is: ");
				//inorder(root);
				displayBST(root, "graph.dot");
				system("dot -Tpng graph.dot -o graph.png");
				break;
			case 7:
				flag=0;
				break;
			default:
				printf("\nEnter a valid input");
		}	
	}
	return 0;
}
