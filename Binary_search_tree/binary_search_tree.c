#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;

}node;

node *root = NULL,*pos=NULL;

void trav(node *temp){
    if(temp != NULL){
    printf("%d\t", temp->data);
    trav(temp->left);
    trav(temp->right);
    }
}

node *search(int value,node *temp){
    if(temp!=NULL){
        if(temp->data == value)
            pos=temp;
        search(value,temp->left);
        search(value,temp->right);
    }
    return NULL;
}

void insert(int value){
    node *new = (node *) malloc(sizeof(node)),*temp=root;
    new->data=value;
    new->left=new->right=NULL;
    while(1){
        if (root == NULL){
            root = new;
            break;
        }
        else if(value < temp->data){
            if(temp->left == NULL){
                temp->left = new;
                break;
            }
            else
                temp = temp->left;
        }
        else if(value > temp->data){
            if(temp->right == NULL){
                temp->right = new;
                break;
            }
            else
                temp = temp->right;
        }
    }
}
// node *insert(int value,node *temp){
    // if(temp == NULL){
        // temp = (node *)malloc(sizeof(node));
        // temp->data = value;
        // temp->left = temp->right = NULL;
        // return temp;
    // }
    // if(value < temp->data)
        // temp->left = insert(value,temp->left);
    // else if(value > temp->data)
        // temp->right = insert(value,temp->right);
    // return temp;
// }
int main(){
    int operation,value;
    while(1){
        printf("\n1. Insert\n2. Traverse\n3. Search\n0. Exit\n");
        scanf("%d",&operation);
        switch (operation)
        {
        case 1:
            printf("Enter the value to insert : ");
            scanf("%d",&value);
            insert(value);
            break;
        case 2:
            printf("\n");
            trav(root);
            break;
        case 3:
            printf("Enter the value to search : ");
            scanf("%d",&value);
            search(value,root);
            printf("%d \t",pos->data);
            break;
        case 0:
            return 0;
        default:
            break;
        }

    }
}