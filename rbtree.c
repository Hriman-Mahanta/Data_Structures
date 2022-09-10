// Write a C program to implement a red black tree

#include <stdio.h>
#include <stdlib.h>

// enum nodeColor
// {
//   RED,
//   BLACK
// };

struct rbNode
{
    int data, color;
    // struct rbNode *link[2];
    struct rbNode *left;
    struct rbNode *right;
    int size;
    int bdepth;
};

// struct rbNode *root = NULL;

// Create a red-black tree
struct rbNode *createNode(int data)
{
    struct rbNode *newnode;
    newnode = (struct rbNode *)malloc(sizeof(struct rbNode));
    newnode->data = data;
    newnode->color = 0;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Insert an node
void insertion(struct rbNode **root, int data)
{
    struct rbNode *stack[98], *ptr, *newnode, *xPtr, *yPtr;
    int dir[98], ht = 0, index;
    ptr = *root;
    if (!(*root))
    {
        *root = createNode(data);
        return;
    }

    stack[ht] = *root;
    dir[ht++] = 0;
    while (ptr != NULL)
    {
        if (ptr->data == data)
        {
            printf("Duplicates Not Allowed!!\n");
            return;
        }
        //   index = (data - ptr->data) > 0 ? 1 : 0;
        //   stack[ht] = ptr;
        //   ptr = ptr->link[index];
        //   dir[ht++] = index;
        // }
        // stack[ht - 1]->link[index] = newnode = createNode(data);
        if ((data - ptr->data) > 0)
        {
            index = 1;
            stack[ht] = ptr;
            ptr = ptr->right;
            dir[ht++] = index;
        }
        else
        {
            index = 0;
            stack[ht] = ptr;
            ptr = ptr->left;
            dir[ht++] = index;
        }
    }
    if (index == 1)
        stack[ht - 1]->right = newnode = createNode(data);
    else
        stack[ht - 1]->left = newnode = createNode(data);

    while ((ht >= 3) && (stack[ht - 1]->color == 0))
    {
        if (dir[ht - 2] == 0)
        {
            yPtr = stack[ht - 2]->right;
            if (yPtr != NULL && yPtr->color == 0)
            {
                stack[ht - 2]->color = 0;
                stack[ht - 1]->color = yPtr->color = 1;
                ht = ht - 2;
            }
            else
            {
                if (dir[ht - 1] == 0)
                {
                    yPtr = stack[ht - 1];
                }
                else
                {
                    xPtr = stack[ht - 1];
                    yPtr = xPtr->right;
                    xPtr->right = yPtr->left;
                    yPtr->left = xPtr;
                    stack[ht - 2]->left = yPtr;
                }
                xPtr = stack[ht - 2];
                xPtr->color = 0;
                yPtr->color = 1;
                xPtr->left = yPtr->right;
                yPtr->right = xPtr;
                if (xPtr == *root)
                {
                    *root = yPtr;
                }
                else
                {
                    if (dir[ht - 3] == 0)
                        stack[ht - 3]->left = yPtr;
                    else
                        stack[ht - 3]->right = yPtr;
                }
                break;
            }
        }
        else
        {
            yPtr = stack[ht - 2]->left;
            if ((yPtr != NULL) && (yPtr->color == 0))
            {
                stack[ht - 2]->color = 0;
                stack[ht - 1]->color = yPtr->color = 1;
                ht = ht - 2;
            }
            else
            {
                if (dir[ht - 1] == 1)
                {
                    yPtr = stack[ht - 1];
                }
                else
                {
                    xPtr = stack[ht - 1];
                    yPtr = xPtr->left;
                    xPtr->left = yPtr->right;
                    yPtr->right = xPtr;
                    stack[ht - 2]->right = yPtr;
                }
                xPtr = stack[ht - 2];
                yPtr->color = 1;
                xPtr->color = 0;
                xPtr->right = yPtr->left;
                yPtr->left = xPtr;
                if (xPtr == *root)
                {
                    *root = yPtr;
                }
                else
                {
                    if (dir[ht - 3] == 0)
                        stack[ht - 3]->left = yPtr;
                    else
                        stack[ht - 3]->right = yPtr;
                }
                break;
            }
        }
    }
    (*root)->color = 1;
}

// Delete a node
void deletion(struct rbNode **root, int data)
{
    struct rbNode *stack[98], *ptr, *xPtr, *yPtr;
    struct rbNode *pPtr, *qPtr, *rPtr;
    int dir[98], ht = 0, diff, i;
    // enum nodeColor color;
    int color;

    if (!(*root))
    {
        printf("Tree not available\n");
        return;
    }

    ptr = *root;
    while (ptr != NULL)
    {
        if ((data - ptr->data) == 0)
            break;
        // diff = (data - ptr->data) > 0 ? 1 : 0;
        stack[ht] = ptr;
        if ((data - ptr->data) > 0)
        {
            dir[ht++] = 1;
            ptr = ptr->right;
        }
        else
        {
            dir[ht++] = 0;
            ptr = ptr->left;
        }
    }

    if (ptr->right == NULL)
    {
        if ((ptr == *root) && (ptr->left == NULL))
        {
            free(ptr);
            *root = NULL;
        }
        else if (ptr == *root)
        {
            *root = ptr->left;
            free(ptr);
        }
        else
        {
            if (dir[ht - 1] == 0)
                stack[ht - 1]->left = ptr->left;
            else
                stack[ht - 1]->right = ptr->left;
        }
    }
    else
    {
        xPtr = ptr->right;
        if (xPtr->left == NULL)
        {
            xPtr->left = ptr->left;
            color = xPtr->color;
            xPtr->color = ptr->color;
            ptr->color = color;

            if (ptr == *root)
            {
                *root = xPtr;
            }
            else
            {
                if (dir[ht - 1] == 0)
                    stack[ht - 1]->left = xPtr;
                else
                    stack[ht - 1]->right = xPtr;
            }

            dir[ht] = 1;
            stack[ht++] = xPtr;
        }
        else
        {
            i = ht++;
            while (1)
            {
                dir[ht] = 0;
                stack[ht++] = xPtr;
                yPtr = xPtr->left;
                if (!yPtr->left)
                    break;
                xPtr = yPtr;
            }

            dir[i] = 1;
            stack[i] = yPtr;
            if (i > 0)
            {
                if (dir[i - 1] == 0)
                    stack[i - 1]->left = yPtr;
                else
                    stack[i - 1]->right = yPtr;
            }
            yPtr->left = ptr->left;

            xPtr->left = yPtr->right;
            yPtr->right = ptr->right;

            if (ptr == *root)
            {
                *root = yPtr;
            }

            color = yPtr->color;
            yPtr->color = ptr->color;
            ptr->color = color;
        }
    }

    if (ht < 1)
        return;

    if (ptr->color == 1)
    {
        while (1)
        {
            if (dir[ht - 1] == 0)
                pPtr = stack[ht - 1]->left;
            else
                pPtr = stack[ht - 1]->right;
            if (pPtr && pPtr->color == 0)
            {
                pPtr->color = 1;
                break;
            }

            if (ht < 2)
                break;

            if (dir[ht - 2] == 0)
            {
                rPtr = stack[ht - 1]->right;

                if (!rPtr)
                    break;

                if (rPtr->color == 0)
                {
                    stack[ht - 1]->color = 0;
                    rPtr->color = 1;
                    stack[ht - 1]->right = rPtr->left;
                    rPtr->left = stack[ht - 1];

                    if (stack[ht - 1] == *root)
                    {
                        *root = rPtr;
                    }
                    else
                    {
                        if (dir[ht - 2] == 0)
                            stack[ht - 2]->left = rPtr;
                        else
                            stack[ht - 2]->right = rPtr;
                    }
                    dir[ht] = 0;
                    stack[ht] = stack[ht - 1];
                    stack[ht - 1] = rPtr;
                    ht++;

                    rPtr = stack[ht - 1]->right;
                }

                if ((!rPtr->left || rPtr->left->color == 1) &&
                    (!rPtr->right || rPtr->right->color == 1))
                {
                    rPtr->color = 0;
                }
                else
                {
                    if (!rPtr->right || rPtr->right->color == 1)
                    {
                        qPtr = rPtr->left;
                        rPtr->color = 0;
                        qPtr->color = 1;
                        rPtr->left = qPtr->right;
                        qPtr->right = rPtr;
                        rPtr = stack[ht - 1]->right = qPtr;
                    }
                    rPtr->color = stack[ht - 1]->color;
                    stack[ht - 1]->color = 1;
                    rPtr->right->color = 1;
                    stack[ht - 1]->right = rPtr->left;
                    rPtr->left = stack[ht - 1];
                    if (stack[ht - 1] == *root)
                    {
                        *root = rPtr;
                    }
                    else
                    {
                        if (dir[ht - 2] == 0)
                            stack[ht - 2]->left = rPtr;
                        else
                            stack[ht - 2]->right = rPtr;
                    }
                    break;
                }
            }
            else
            {
                rPtr = stack[ht - 1]->left;
                if (!rPtr)
                    break;

                if (rPtr->color == 0)
                {
                    stack[ht - 1]->color = 0;
                    rPtr->color = 1;
                    stack[ht - 1]->left = rPtr->right;
                    rPtr->right = stack[ht - 1];

                    if (stack[ht - 1] == *root)
                    {
                        *root = rPtr;
                    }
                    else
                    {
                        if (dir[ht - 2] == 0)
                            stack[ht - 2]->left = rPtr;
                        else
                            stack[ht - 2]->right = rPtr;
                    }
                    dir[ht] = 1;
                    stack[ht] = stack[ht - 1];
                    stack[ht - 1] = rPtr;
                    ht++;

                    rPtr = stack[ht - 1]->left;
                }
                if ((!rPtr->left || rPtr->left->color == 1) &&
                    (!rPtr->right || rPtr->right->color == 1))
                {
                    rPtr->color = 0;
                }
                else
                {
                    if (!rPtr->left || rPtr->left->color == 1)
                    {
                        qPtr = rPtr->right;
                        rPtr->color = 0;
                        qPtr->color = 1;
                        rPtr->right = qPtr->left;
                        qPtr->left = rPtr;
                        rPtr = stack[ht - 1]->left = qPtr;
                    }
                    rPtr->color = stack[ht - 1]->color;
                    stack[ht - 1]->color = 1;
                    rPtr->left->color = 1;
                    stack[ht - 1]->left = rPtr->right;
                    rPtr->right = stack[ht - 1];
                    if (stack[ht - 1] == *root)
                    {
                        *root = rPtr;
                    }
                    else
                    {
                        if (dir[ht - 2] == 0)
                            stack[ht - 2]->left = rPtr;
                        else
                            stack[ht - 2]->right = rPtr;
                    }
                    break;
                }
            }
            ht--;
        }
    }
}

// Print the inorder traversal of the tree
void inorderTraversal(struct rbNode *node)
{
    if (node)
    {
        inorderTraversal(node->left);
        printf("%d", node->data);
        inorderTraversal(node->right);
    }
    return;
}

char *colorGraph(int c)
{
    if (c == 0)
        return "red";
    else
        return "black";
}

void generateGraph(struct rbNode *root, FILE *fp)
{
    if (root != NULL)
    {
        fprintf(fp, "%d[label=\"%d\", color=%s];\n", root->data, root->data, colorGraph(root->color));
        if (root->left != NULL)
        {
            fprintf(fp, "%d -> %d [color = blue];\n", root->data, root->left->data);
            generateGraph(root->left, fp);
        }
        if (root->right != NULL)
        {
            fprintf(fp, "%d-> %d ;\n", root->data, root->right->data);
            generateGraph(root->right, fp);
        }
    }
}

int displayBST(struct rbNode *root, char *filename)
{
    FILE *fp;
    fp = fopen(filename, "w+");
    if (fp == NULL)
        return -1;
    fprintf(fp, "digraph g{\n");
    generateGraph(root, fp);
    fprintf(fp, "}\n");
    fclose(fp);

    return 0;
}

// Driver code
int main()
{
    int ch, data;
    struct rbNode *root = NULL;
    while (1)
    {
        printf("1. Insertion\t2. Deletion\n");
        printf("3. Traverse\t4. Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to insert:");
            scanf("%d", &data);
            insertion(&root, data);
            break;
        case 2:
            printf("Enter the element to delete:");
            scanf("%d", &data);
            deletion(&root, data);
            break;
        case 3:
            inorderTraversal(root);
            displayBST(root, "graph.dot");
            system("dot -Tpng graph.dot -o graph.png");
            printf("\n");
            break;
        case 4:
            exit(0);
        default:
            printf("Not available\n");
            break;
        }
        printf("\n");
    }
    return 0;
}
