#include <stdio.h>

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

// void merge(int a[], int first, int mid, int last)
// {
//     int i = first, j = mid + 1, k = first, b[50];
//     while (i <= mid && j <= last)
//     {
//         if (a[i] <= a[j])
//             b[k++] = a[i++];
//         //
//         else
//             b[k++] = a[j++];
//     }
//     //
//     // while (i < n1) {
//     // a[k] = L[i];
//     // i++;
//     // k++;
//     // }
//     // while (j < n2) {
//     // a[k] = M[j];
//     // j++;
//     // k++;
//     // }
//     // while(i>mid?(j <= last):(i < mid))
//     // b[k++]=i>mid?a[j++]:a[i++];
//     if (i > mid)
//     {
//         while (j <= last)
//             b[k++] = a[j++];
//     }
//     else
//     {
//         while (i < mid)
//             b[k++] = a[i++];
//     }
//     for (i = first; i <= last; i++)
//         a[i] = b[i];
// }


void merge_sort(int arr[], int first, int last)
{
    
    if (first < last)
    {
        int mid = (first + last) / 2;
        merge_sort(arr, first, mid);
        merge_sort(arr, mid + 1, last);
        
    }
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter the %d element: ", i + 1);
        scanf("%d", &arr[i]);
    }
    while (1)
    {
        printf("\n0.EXIT\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort \nSelect a method :");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            for (int i = 0; i < size; i++) // bubble sort
                for (int i = 0; i < size - 1; i++)
                    arr[i] < arr[i + 1] ? arr[i] : swap(arr + i, arr + i + 1);
            break;
        case 2:
            for (int i = 0; i < size; i++) // selection sort
                for (int j = i; j < size; j++)
                    arr[i] < arr[j] ? 0 : swap(arr + i, arr + j);
            break;
        case 3:
            for (int i = 0; i < size; i++) // insertion sort
                for (int j = i - 1; j > 0; j--)
                    arr[i] < arr[j] ? swap(arr + i, arr + j) : 0;
            break;
        case 4:
            merge_sort(arr, 0, size - 1);
            break;
        case 0:
            return 0;
        default:
            printf("Invalid Choice\n");
        }
        for (int i = 0; i < size; i++)
            printf("%d\t", arr[i]);
    }
}