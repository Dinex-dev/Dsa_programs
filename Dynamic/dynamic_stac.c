#include <stdio.h>
#include <stdlib.h>

typedef struct dynamic_stack
{
    int data;
    struct dynamic_stack *next;
}item;
item *head = NULL;

int trav(item *start)
{
    if(head==NULL){
        return 0;
    }
    printf("%d\t", start->data);
    if (start->next)
        trav(start->next);
    return 0;
}

void push(int value)
{
    item *new = (item *)malloc(sizeof(item));
    new->next=head?head:NULL;
    head = new;
    new->data = value;
}

int main()
{
    while (1)
    {
        int operator,val;
        printf("\n1. push\n2. pop\n3. Traverse\n0. Exit\nSelect One operation : ");
        scanf("%d", &operator);
        switch (operator)
        {
        case 1:
            printf("Enter a value : ");
            scanf("%d", &val);
            push(val);
            break;
        case 2: 
            head?head=head->next:printf("stack empty");
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