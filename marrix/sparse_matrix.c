#include <stdio.h>
int main()
{
    int rows, cols, zeros = 0;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    int matrix[rows][cols];

    for (int i = 0; i < rows; i++)
    {
        printf("Enter elements of row %d:\n", i + 1);
        for (int j = 0; j < cols; j++)
        {   scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 0)
                zeros++;
        }
    }
    printf("\n");

    if (zeros > ((rows * cols)/2)) // if more than 50% of elements are zero
    { 
        printf("Matrix is sparse\n");
        printf("row \t col \t value\n");
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (matrix[i][j] != 0)
                    printf("%d\t %d\t %d\n", i, j, matrix[i][j]);
    }
    else
        printf("Matrix is not sparse\n\n");
    
    return 0;
}