#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node;
node *front = NULL, *rear = NULL;
void enqueue(int data) {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if (front == NULL) {
        front = temp;
    } else {
        rear->next = temp;
        
    }
    rear = temp;
    rear->next=front;
}
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return ;
    }
    if(front->next==front){
        front=NULL;
        rear=NULL;
    }
    else if(front->next!=front){
        front=front->next;
        rear->next=front;
    }
}
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    node *temp = front->next;
    printf("%d\t", front->data);
    while (temp != front) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoose one operation: ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int data;
            printf("Enter data: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        }
    }
}