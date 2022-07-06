#include <stdio.h>
#include <stdlib.h>
struct dynamic_stack
{
    int data;
    struct dynamic_stack *next;
}*head = NULL;

void trav(struct dynamic_stack *start)
{
    printf("%d\t", start->data);
    if (start->next)
        trav(start->next);
}

void push(int value)
{
    struct dynamic_stack *ptr = (struct dynamic_stack *)malloc(sizeof(struct dynamic_stack));

    if (head == NULL)
    {
        head = ptr;
        ptr->data = value;
        ptr->next = NULL;
    }
    else
    {
        ptr->next = head;
        ptr->data = value;
        head = ptr;
    }
}
void pop(){

}
int main()
{
    while (1)
    {
        int operator,val;
        printf("\n1. push\n2. pop\n3. Traverse\n4. selection_sort\n5. Exit\nSelect One operation : ");
        scanf("%d", &operator);
        switch (operator)
        {
        case 1:
            printf("Enter a value : ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            
            break;
        case 3:
            trav(head);
            break;
        case 4:
            
            break;
        case 5:
            return 0;
        default:
            printf("invalid operator %d", operator);
            break;
        }
    }
}