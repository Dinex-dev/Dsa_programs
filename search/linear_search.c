#include <stdio.h>
int main(){
    int size=0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int array[size];
    for (int i = 0; i < size ; i++)
    {
        printf("Enter the %d element: ", i+1);
        scanf("%d", &array[i]);
    }
    printf("Enter the element to be searched: ");
    int key;
    scanf("%d", &key);
    for (int i=0; i<size; i++){
        if (array[i]==key){
            printf("Element found at index %d\n", i);
            return 0;
        }
    }
    printf("Element not found\n");   
}