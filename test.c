#include <stdio.h>

int sort(int arr[],int size)
{
    int spam;
    for (int i=0;i<size-1;i++)
    {	
        for (int j=0;j<size-1;j++)
        {
            if (arr[j]>arr[j+1])
            {
                spam=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=spam;
            }
        }
        printf("\n");
    }
    return 0;
}
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
    sort(array,size);
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", array[i]);
    }
    
}