#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;
node *head = NULL , *tail = NULL;

void traverse(node *start)
{
    printf("%d\t", start->data);
    if (start->next)
        traverse(start->next);
}

void insert(int value)
{
    node *new = (node *)malloc(sizeof(node));
    !head?(head=new):(tail->next=new);
    new->data = value;
    new->next = NULL;
    tail = new;
}
void delete ()
{
    node *temp = head;
    while (temp->next != tail)
        temp = temp->next;
    printf("\n%d deleted\n", tail->data);
    free(tail);
    tail = temp;
    tail->next = NULL;
}
int main()
{
    int operator, val;
    while (1)
    {
        printf("\n1. insertion\n2. Deletion\n3. Traverse\n0. Exit\nSelect One operation : ");
        scanf("%d", &operator);
        switch (operator)
        {
        case 1:
            printf("Enter a value : ");
            scanf("%d", &val);
            insert(val);
            break;
        case 2:
            delete();
            break;
        case 3:
            printf("\n");
            traverse(head);
            printf("\n");
            break;
        case 0:
            return 0;
        default:
            printf("invalid operator %d", operator);
            break;
        }
    }
}