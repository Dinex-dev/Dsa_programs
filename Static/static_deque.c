#include <stdio.h>
int main(){
    int size;
    printf("Enter the size of the deque: ");
    scanf("%d", &size);
    int deque[size],front = -1,rear = -1,choice,element;
    while(1){
        printf("\n1. Insert at rear\n2. Delete from front\n3. Delete from rear\n4. Display\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &element);
                if(front == -1){
                    front = 0;
                    rear = 0;
                }
                else if(rear == size-1){
                    printf("Deque is full\n");
                    break;
                }
                else{
                    rear++;
                }
                deque[rear] = element;
                break;
            case 2:
                if(front == -1){
                    printf("Deque is empty\n");
                }
                else{
                    printf("The element deleted is %d\n", deque[front]);
                    front++;
                }
                break;
            case 3:
                if(rear == -1){
                    printf("Deque is empty\n");
                }
                else{
                    printf("The element deleted is %d\n", deque[rear]);
                    rear--;
                }
                break;
            case 4:
                if(front == -1){
                    printf("Deque is empty\n");
                }
                else{
                    printf("The deque is: ");
                    for(int i=front; i<=rear; i++){
                        printf("%d ", deque[i]);
                    }
                    printf("\n");
                }
                break;
            case 0:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}