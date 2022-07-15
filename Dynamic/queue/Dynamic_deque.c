#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;
node *head = NULL , *tail = NULL;

void display(node *start)
{
    printf("%d\t", start->data);
    if (start->next)
        display(start->next);
}

void enqueue(int value)
{
    node *new = (node *)malloc(sizeof(node));
    !head?(head=new):(tail->next=new);
    new->data = value;
    new->next = NULL;
    tail = new;
}
void dequeue_rear ()
{
    node *temp = head;
    while (temp->next != tail)
        temp = temp->next;
    printf("\n%d deleted\n", tail->data);
    free(tail);
    tail = temp;
    tail->next = NULL;
}
void dequeue_front ()
{
    node *temp = head;
    printf("\n%d deleted\n", head->data);
    head = head->next;
    free(temp);
}
int main()
{
    int operator, val;
    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue from rear\n3. Dequeue from front \n4. Display\n0. Exit\nSelect One operation : ");
        scanf("%d", &operator);
        switch (operator)
        {
        case 1:
            printf("Enter a value : ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue_rear();
            break;
        case 3:
            dequeue_front();
            break;
        case 4:
            printf("\n");
            display(head);
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