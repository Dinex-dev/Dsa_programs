#include <stdio.h>
int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}
int main()
{
    int array[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < i; j++)
        {
            array[i] > array[j] ? swap(&array[i], &array[j]) : 0;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
}