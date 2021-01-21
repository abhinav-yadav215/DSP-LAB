#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} tree_node;

tree_node *insert_node(tree_node *root, int value)
{
    if (root == NULL)
    {
        root = (tree_node *)malloc(sizeof(tree_node));
        root->data = value;
        root->left = root->right = NULL;
    }
    else
    {
        if (value > root->data)
        {
            root->right = insert_node(root->right, value);
        }
        if (value < root->data)
        {
            root->left = insert_node(root->left, value);
        }
    }
    return root;
}

void preorder(tree_node *root)
{
    if (root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(tree_node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

void postorder(tree_node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}

int main()
{
    tree_node *root = NULL;
    int number_of_nodes;
    int node;
    scanf("%d", &number_of_nodes);
    
    int i;
    for (i= 0; i < number_of_nodes; i++)
    {
        scanf("%d", &node);
        root = insert_node(root, node);
    }

    preorder(root);
    printf("\n");

    inorder(root);
    printf("\n");

    postorder(root);

    return 0;
}
