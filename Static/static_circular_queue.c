#include <stdio.h>

int main(){
    int size;
    printf("Enter size of queue: ");
    scanf("%d", &size);
    int arr[size];
    int front = -1;
    int rear = -1;
    int choice;
    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoose one operation: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (rear == size - 1)
            {
                printf("Queue is full\n");
                break;
            }
            if (front == -1)
            {
                front = 0;
            }
            rear++;
            printf("Enter data: ");
            scanf("%d", &arr[rear]);
            break;
        case 2:
            if (front == -1)
            {
                printf("Queue is empty\n");
                break;
            }
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front++;
            }
            break;
        case 3:
            if (front == -1)
            {
                printf("Queue is empty\n");
                break;
            }
            int i;
            for (i = front; i <= rear; i++)
            {
                printf("%d\t", arr[i]);
            }
            printf("\n");
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}