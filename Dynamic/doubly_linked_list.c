#include <stdio.h>
#include <stdlib.h>
typedef struct doubly_linked_list
{
    struct doubly_linked_list *prev, *next;
    int data;
} node;

node *head=NULL, *tail=NULL;

void push(int value)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = value;
    if (head == NULL)
    {
        new->next = NULL;
        new->prev = NULL;
        head = new;
        tail = new;
    }
    else
    {
        new->next = NULL;
        new->prev = tail;
        tail->next = new;
        tail = new;
    }
}
void trav(node *temp)
{
    while (temp)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
int pop(){
    if(!head){
        printf("underflow");
        return 0;
    }
    head=tail->prev?head:NULL;
    tail= tail->prev;
    tail->next=NULL;
    return 1;
}

int main()
{
    int operator, val;
    while (1)
    {
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
            pop();
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