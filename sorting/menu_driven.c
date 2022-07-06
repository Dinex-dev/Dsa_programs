#include <stdio.h>

void print_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d\t", *(arr + i));
}

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return *a;
}

void merge(int arr[], int first, int mid, int last)
{
    int i = first, j = mid + 1, k = first, arr2[50];
    while (i <= mid && j <= last)
    {
        if (arr[i] <= arr[j])
            arr2[k++] = arr[i++];

        else
            arr2[k++] = arr[j++];
    }
    if (i > mid)
    {
        while (j <= last)
            arr2[k++] = arr[j++];
    }
    else
    {
        while (i < mid)
            arr2[k++] = arr[i++];
    }
    for (i = first; i < last; i++)
        arr[i] = arr2[i];
}

void merge_sort(int arr[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        merge_sort(arr, first, mid);
        merge_sort(arr, mid + 1, last);
        merge(arr, first, mid, last);
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
        printf("\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            for (int j = 0; j < size; j++) // bubble sort
                for (int i = 0; i < size - 1; i++)
                    arr[i] = arr[i] < arr[i + 1] ? arr[i] : swap(arr + i, arr + i + 1);
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
        default:
            printf("Invalid Choice\n");
        }
        print_arr(arr, size);
    }
}