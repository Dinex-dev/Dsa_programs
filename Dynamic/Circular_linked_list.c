#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head = NULL, *tail = NULL;

void trav(struct node *start)
{
    if(head){
    printf("%d\t", start->data);
    if (start->next != head)
        trav(start->next);
    }
    else{
        printf("list is empty");
    }
}

void insert(int value)
{
    struct node *new = (struct node *)malloc(sizeof(struct node)), *temp = head;
    new->data = value;
    new->next = head;

    if (!head)
    {
        head = new;
        head->next = head;
    }
    else
    {
        while (temp->next != head)
            temp = temp->next;
        temp->next = new;
    }
}
void delete ()
{
    struct node *temp = head;
    while (temp->next->next != head)
        temp = temp->next;
    printf("%d deleted", temp->next->data);
    if (head != NULL && head->next != head)
    {
        temp->next = head;
    }
    else
    {
        head = NULL;
    }
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
            delete ();
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