#include <stdio.h>
int sort(int arr[], int size)
{
    int spam;
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                spam = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = spam;
            }
    return 0;
}
int main()
{
    int size = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int array[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter the %d element: ", i + 1);
        scanf("%d", &array[i]);
    }
    printf("Enter the element to be searched: ");
    int key, method;
    scanf("%d", &key);
    printf("Which method do you want to use?\n1. Linear search\n2. Binary search !! Using Binary Search Will Sort the array automatically\n");
    scanf("%d", &method);
    switch (method)
    {
    case 1:
        for (int i = 0; i < size; i++)
        {
            if (array[i] == key)
            {
                printf("%d found at index %d\n",key, i);
                return 0;
            }
        }
        break;
    case 2:
        sort(array, size);
        int min=0,max=size-1,mid;
        while ((array[mid]!=key)||(min>max)){
            mid=(min+max)/2;
            if (array[mid]>key)
                max=mid-1;
            else if(array[mid]==key){
                printf("%d found at index %d\n",key, mid);
                return 0;
            }
            else
                min=mid+1;
        }

        break;

    default:
        break;
    }
    printf("Element not found\n");
}