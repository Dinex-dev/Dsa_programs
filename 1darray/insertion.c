#include <stdio.h>
int main(){
    int size,pos,ele;
    printf("input size of array : ");
    size=4;
    int arr[]={1,2,3,4,0};
    
    

    pos=2;

    ele=343;
    

    for (int i= 0; i<size-pos+1; i++)
    {
        arr[size-i]=arr[size-i-1];
    }
    
    // for (int i = size+1; i >= pos; i--)
    // {
        // arr[i]=arr[i-1];
    // }
    arr[pos-1]=ele;
    for (int i = 0; i < size+1; i++)
    {
        printf("%d \t",arr[i]);
    }
}