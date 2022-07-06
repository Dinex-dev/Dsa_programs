#include <stdio.h>
int mergesort(int arr,int l,int t){
    if(l>=t)
        return 0;
    int m=(l+t)/2;
    mergesort(arr,l,m);
    mergesort(arr,m,t);
}
int main(){
    int size=0;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    int arr[size];
    for (int i=0;i<size;i++){
        printf("Enter %d th element : ");
        scanf("%d",arr[i]);
    }
    mergesort(arr,0,size);
}