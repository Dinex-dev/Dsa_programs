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
    for (int i = 0; i < size; i++)
    { 
        for (int j=0;j<size-i-1;j++){
            if (array[j]>array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }

        }
    }
    printf("Sorted array: \n");
    for (int i=0; i<size; i++){
        printf("%d\t", array[i]);
    }   
}