#include <stdio.h>

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    // Create temp arrays
    int L[n1], R[n2];
    // Copy data to temp array
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    // Merge the temp arrays
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R[]
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Finding mid element
        int m = l + (r - l) / 2;
        // Recursively sorting both the halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the array
        merge(arr, l, m, r);
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
                insertionSort(arr, size);
            break;
        case 4:
            mergeSort(arr, 0, size - 1);
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