#include <stdio.h>
int main(){
    int size;
    printf("Enter the size of the stack: ");
    scanf("%d",&size);
    int stack[size],top=-1,option=0;
    while(option!=4){
    printf("----------------------------------------------------\n");
    printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
    printf("----------------------------------------------------\n");
    scanf("%d",&option);
        switch(option){
            case 1:
                if(top==size-1){
                    printf("Stack is full\n");
                }
                else{
                    printf("Enter the element to be pushed: ");
                    scanf("%d",&stack[++top]);
                }
                break;
            case 2:
                if(top==-1){
                    printf("Stack is empty\n");
                }
                else{
                    printf("Popped element is %d\n",stack[top--]);
                }
                break;
            case 3:
                if(top==-1){
                    printf("Stack is empty\n");
                }
                else{
                    printf("Stack elements are: ");
                    for(int i=top;i>=0;i--){
                        printf("%d ",stack[i]);
                    }
                    printf("\n");
                }
                break;
            case 4:
                return 0;
            default:
                printf("Invalid option\n");
        }
    }
}