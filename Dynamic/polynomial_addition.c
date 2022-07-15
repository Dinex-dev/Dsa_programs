#include <stdio.h>
#include <stdlib.h>
typedef struct polynomial
{
    int coefficient;
    int exponent;
    struct polynomial *next;
} polynomial;

int main()
{
    polynomial *poly1 = NULL, *poly2 = NULL;
    int size1, size2;
    printf("Enter exponent of polynomial 1 : ");
    scanf("%d", &size1);
    printf("Enter exponent of polynomial 2 : ");
    scanf("%d", &size2);

    printf("\nEnter values of polynomial 1 \n");
    for (int i = 0; i < size1; i++)
    {
        polynomial *temp = (polynomial *)malloc(sizeof(polynomial));
        printf("Enter coefficient of X^%d term : ", i);
        scanf("%d", &temp->coefficient);
        temp->exponent = i;
        temp->next = poly1 ? poly1 : NULL;
        poly1 = temp;
    }
    
    printf("\nEnter values of polynomial 2 \n");
    for (int i = 0; i < size2; i++)
    {
        polynomial *temp = (polynomial *)malloc(sizeof(polynomial));
        printf("Enter coefficient of X^%d term : ", i);
        scanf("%d", &temp->coefficient);
        temp->exponent = i;
        temp->next = poly2 ? poly2 : NULL;
        poly2 = temp;
    }
    polynomial *sum = NULL;
    polynomial *temp1 = poly1, *temp2 = poly2;
    while (temp1 && temp2)
    {
        polynomial *temp = (polynomial *)malloc(sizeof(polynomial));

        if (temp1->exponent > temp2->exponent)
        {
            temp->coefficient = temp1->coefficient;
            temp->exponent = temp1->exponent;
            temp1 = temp1->next;
        }
        else if (temp1->exponent < temp2->exponent)
        {
            temp->coefficient = temp2->coefficient;
            temp->exponent = temp2->exponent;
            temp2 = temp2->next;
        }
        else
        {
            temp->coefficient = temp1->coefficient + temp2->coefficient;
            temp->exponent = temp1->exponent;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp->next = sum;
        sum = temp;
    }
    while (temp1)
    {
        polynomial *temp = (polynomial *)malloc(sizeof(polynomial));
        temp->coefficient = temp1->coefficient;
        temp->exponent = temp1->exponent;
        temp->next = sum;
        sum = temp;
        temp1 = temp1->next;
    }
    while (temp2)
    {
        polynomial *temp = (polynomial *)malloc(sizeof(polynomial));
        temp->coefficient = temp2->coefficient;
        temp->exponent = temp2->exponent;
        temp->next = sum;
        sum = temp;
        temp2 = temp2->next;
    }
    printf("Sum of polynomial 1 and polynomial 2 is : ");
    while (sum)
    {
        printf("%dx^%d + ", sum->coefficient, sum->exponent);
        sum = sum->next;
    }
    printf("\n");
    return 0;
}