#include <stdio.h>
int main(){
    int size;
    printf("!!! array will be sorted automatically !!!\n");
    printf("enter the size of array :");
    scanf("%d",&size);
    int arr[size],spam,find;
    for (int i = 0; i < size; i++)
    {
        printf("Enter %d'th element : ",i+1); 
        scanf("%d",&arr[i]);
    }
    for (int i=0;i<size-1;i++)
	{	
		for (int j=0;j<size-1;j++)
		{
			if (arr[j]>arr[j+1])
			{
				spam=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=spam;
			}
		}
		printf("\n");
	}
    printf("sorted array : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d \t",arr[i]);
    }
    int flag=0,mid=size;
    printf("\nEnter the element to be searched : ");
    scanf("%d",&find);
    while (flag==0)
    {
        if (arr[mid]==find)
        {
            printf("%d found at index %d\n",find,mid);
            flag=1;
        }
        else if (arr[mid]<find)
        {
            mid=mid/2;
        }
        else if (arr[mid]>find)
        {
            mid=mid+mid/2;
        }
    }
    return 0;
}