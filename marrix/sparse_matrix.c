#include <stdio.h>
int main()
{
    int rows, cols, zero = 0;
    printf("Enter rows of matrix: ");
    scanf("%d", &rows);
    printf("Enter columns of matrix: ");
    scanf("%d", &cols);
    int matrix[rows][cols];
    for (int i = 0; i < rows; i++)
    {
        printf("Enter elements of %d' st/nd row: ", i + 1);
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);
    }
    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
                zero++;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    if (zero > (7 / 10) * (rows * cols))// if more than 70% of elements are zero
    { 
        printf("Matrix is sparse\n");
        printf("row \t col \t value\n");
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (matrix[i][j] != 0)
                {
                    printf("%d\t %d\t %d\n", i, j, matrix[i][j]);
                }
    }
    else
        printf("Matrix is not sparse\n");
    
    return 0;
}