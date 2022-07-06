#include <stdio.h>
int main()
{
    int size,del;
    printf("enter the size of array :");
    size=4;
    int arr[]={1,2,3,4,0};

    printf("your array is  : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d \t",arr[i]);
    }
    printf("\nWhich index do you want to delete : ");
    del=3;
    for (int i = del-1; i < size-1; i++)
    {
        arr[i]=arr[i+1];
    }
    for (int i = 0; i < size-1; i++)
    {
        printf("%d \t",arr[i]);
    }
    return 0;
}