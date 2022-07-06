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
    for(int i=0; i<size-1; i++)
        for (int j=i+1; j<size; j++){
            if (array[i]>array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    printf("Sorted array: \n");
    for (int i=0; i<size; i++){
        printf("%d\t", array[i]);
    }
    return 0;
}