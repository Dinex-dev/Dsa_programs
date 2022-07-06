#include <stdio.h>
int main(){
    int size;
    printf("enter the size of array :");
    scanf("%d",&size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter %d'th element : ",i); 
        scanf("%d",&arr[i]);
    }
    printf("your array is  : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d \t",arr[i]);
    }
}