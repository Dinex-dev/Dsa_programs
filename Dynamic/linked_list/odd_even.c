#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void enqueue(node **head, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL)
        *head = new_node;
    else
    {
        node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}

int main()
{
    int values[10];
    for (int i = 0; i < 10; i++)
        scanf("%d", &values[i]);
    node *even = NULL, *odd = NULL;
    for (int i = 0; i < 10; i++)
    {
        if (values[i] % 2 == 0)
            enqueue(&even, values[i]);
        else
            enqueue(&odd, values[i]);
    }

    printf("Even: ");
    while (even != NULL)
    {
        printf("%d ", even->data);
        even = even->next;
    }
    printf("\nOdd: ");
    while (odd != NULL)
    {
        printf("%d ", odd->data);
        odd = odd->next;
    }
    return 0;
}