#include <stdio.h>


int main()
{
    int location,array[]={1,2,3,4},size=4;
    printf("Enter the location of the element that you want to delete : \n");
            scanf("%d", &location);
            for (int i = location; i < size ; i++)
            {
                array[i - 1] = array[i];
            }
            for (int i = 0; i < size ; i++)
            {
                printf("%d ", array[i]);
            }

    return 0;
}
