#include <stdio.h>
#include <stdlib.h>
typedef struct polynomial
{
    int coefficient;
    int exponent;
    struct polynomial *next;    
} polynomial;

polynomial create_polynomial(int exponent,int coefficient[],void next){
    polynomial *new = (polynomial *)malloc(sizeof(polynomial));
    new->coefficient = coefficient[exponent];
    new->exponent = exponent;
    new->next = next;
    return *new;
}

int main(){
    int n;
    printf("Enter the number of polynomials: ");
    scanf("%d",&n);
    polynomial all_polynomials[n];
    for(int i=0;i<n;i++){
        printf("Enter the exponent of polynomial %d: ",i+1);
        int exponent;
        scanf("%d",&exponent);
        int coefficient[exponent];
        for(int j=0;j<=exponent;j++){
            printf("Enter the coefficient of x^%d: ",j);
            scanf("%d",&coefficient[j]);
        }
        all_polynomials[i] = create_polynomial(exponent,coefficient);
    }
    printf("Sum of all the polynomials : ");
    // find greatest exponent of all the polynomials and create a polynomial of that exponent
    int greatest_exponent = 0;
    for(int i=0;i<n;i++){
        if(all_polynomials[i].exponent > greatest_exponent){
            greatest_exponent = all_polynomials[i].exponent;
        }
    }
    int sum[greatest_exponent];
    printf("\n Greatest poly = %d",greatest_exponent);
    for(int i=greatest_exponent;i>0;i--){
        sum[i]=0;
        for(int j=0;j<n;j++){
            if(all_polynomials[j].exponent == i){
                sum[i] += all_polynomials[j].coefficient;
                all_polynomials[j]=*all_polynomials[j].next;
            }
            printf("%d",sum[i]);
        }   
    }
    // polynomial sum_polynomial = create_polynomial(greatest_exponent,sum);

    return 0;
    }