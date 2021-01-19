#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *insert_node(Node *root, int value)
{
    if (root == NULL)
    {
        root = (Node *)malloc(sizeof(Node));
        root->data = value;
        root->left = root->right = NULL;
    }
    else
    {
        if (value > root->data)
            root->right = insert_node(root->right, value);
        else
            root->left = insert_node(root->left, value);
    }
    return root;
}

int max(int a, int b) 
{ 
return (a < b ? b : a); 
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left),height(root->right)) + 1;
}

int main()
{
    Node *root = NULL;
    int no_of_nodes;
    int node;

    printf("\n enter number of nodes: ");
    scanf("%d", &no_of_nodes);

    printf("\n insert the nodes: ");
    int i;
    for (i = 0; i < no_of_nodes; i++)
    {
        scanf("%d", &node);
        root = insert_node(root, node);
    }

    printf("\n HEIGHT : ");
    printf("%d",height(root));

    printf("\n");

    return 0;
}

