#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head = NULL, *tail = NULL;

void trav(struct node *start)
{
    printf("%d\t", start->data);
    if (start->next)
        trav(start->next);
}

void insert(int value)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    !head?(head=new):(tail->next=new);
    new->data = value;
    new->next = NULL;
    tail = new;
}
void delete ()
{
    struct node *temp = head;
    while (temp->next != tail)
        temp = temp->next;

    printf("%d deleted\n", tail->data);
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
            trav(head);
            break;
        case 0:
            return 0;
        default:
            printf("invalid operator %d", operator);
            break;
        }
    }
}