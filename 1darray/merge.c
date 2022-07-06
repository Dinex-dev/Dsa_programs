#include <stdio.h>
int main()
{
    int size1,size2;
    printf("Enter the size of array 1 : ");
    scanf("%d",&size1);
    printf("Enter the size of array 2 : ");
    scanf("%d",&size2);
    int arr1[size1],arr2[size2];
    for (int i = 0; i < size1; i++)
    {
        printf("Enter %d'th element of 1st array : ",i+1); 
        scanf("%d",&arr1[i]);
    }
    for (int i = 0; i < size2; i++)
    {
        printf("Enter %d'th element of 2nd array : ",i+1); 
        scanf("%d",&arr2[i]);
    }
    printf("Merged array is : \n");
    int arr3[size1+size2];
    for (int i = 0; i < size1; i++)
    {
        arr3[i]=arr1[i];
    }
    for (int i = 0; i < size2; i++)
    {
        arr3[i+size1]=arr2[i];

    }
    for (int i = 0; i < size1+size2; i++)
    {
        printf("%d \t",arr3[i]);
    }
    
}