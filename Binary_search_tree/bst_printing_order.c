#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node *left;
	struct node *right;
	int data;
} node;

node *root = NULL;

node *preorder(node *temp)
{
	if (temp == NULL)
		return NULL;
	printf("%d\t", temp->data);
	preorder(temp->left);
	preorder(temp->right);
}

node *inorder(node *temp)
{
	if (temp == NULL)
		return NULL;
	inorder(temp->left);
	printf("%d\t", temp->data);
	inorder(temp->right);
}

node *postorder(node *temp)
{
	if (temp == NULL)
		return NULL;
	postorder(temp->left);
	postorder(temp->right);
	printf("%d\t", temp->data);
}

node *createNode(int data)
{
	node *n = (node *)malloc(sizeof(node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

node *insert(node *root, int data)
{
	if (root == NULL)
		root = createNode(data);
	else if (root->data < data)
		root->right = insert(root->right, data);
	else
		root->left = insert(root->left, data);

	return root;
}

int main()
{
	node *root = NULL;
	int arr[] = {10, 7, 15, 8, 9, 13, 12, 20, 18, 25};
	for (int i = 0; i < 10; i++)
		root = insert(root, arr[i]);
	printf("Preorder: \t");
	preorder(root);
	printf("\nInorder: \t");
	inorder(root);
	printf("\nPostorder: \t");
	postorder(root);
	return 0;
}
