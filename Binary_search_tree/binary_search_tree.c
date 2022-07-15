#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;

} node;

node *root = NULL, *pos = NULL;

void trav(node *temp)
{
    if (temp == NULL)
        return;
    printf("%d\t",temp->data);
    trav(temp->left);
    trav(temp->right);
}

node *search(int value, node *temp)
{
    if (temp != NULL)
    {
        if (temp->data == value)
            pos = temp;
        search(value, temp->left);
        search(value, temp->right);
    }
    return NULL;
}
struct node* createNode(int val){
	struct node* n = (struct node*)malloc(sizeof(struct node));
	n->data = val;
	n->left = NULL;
	n->right = NULL;
	return n;
}


node *insert(int value, node *temp)
{
    if (temp)
    {
        if (temp->left == NULL && temp->data > value)
        {
            temp->left = (node *)malloc(sizeof(node));
            temp->left->data = value;
            temp->left->left = temp->left->right = NULL;
        }
        else if (temp->right == NULL && temp->data <= value)
        {
            temp->right = (node *)malloc(sizeof(node));
            temp->right->data = value;
            temp->right->left = temp->right->right = NULL;
        }
        else if (temp->data > value)
        {
            insert(value, temp->left);
        }
        else if (temp->data <= value)
        {
            insert(value, temp->right);
        }
    }
    else{
        root=(node *)malloc(sizeof(node));
        root->data=value;
        root->left=root->right=NULL;
    }
    return NULL;
}

int main()
{
    int operation, value;
    while (1)
    {
        printf("\n1. Insert\n2. Traverse\n3. Search\n0. Exit\n");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            printf("Enter the value to insert : ");
            scanf("%d", &value);
            insert(value, root);
            // insert(value);
            break;
        case 2:
            printf("\n");
            trav(root);
            break;
        case 3:
            printf("Enter the value to search : ");
            scanf("%d", &value);
            search(value, root);
            printf("%d's address is : %X\n",value, &pos->data);
            break;
        case 0:
            return 0;
        default:
            break;
        }
    }
}