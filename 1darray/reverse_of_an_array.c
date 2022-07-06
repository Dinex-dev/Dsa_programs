#include <stdio.h>
int main()
{
	int len;
	printf("Enter length of the array : ");
	scanf("%d",&len);
	int arr[len],arr2[len];
	for (int i=0;i<len;i++){
		printf("Enter %d value : ",i+1);
		scanf("%d",&arr[i]);
	}
	for (int i = 0; i < len/2; ++i)
	{
		arr[i]=arr[i]+arr[len-i-1];
		arr[len-i-1]=arr[i]-arr[len-i-1];
		arr[i]=arr[i]-arr[len-i-1];
	}
	for (int i=0;i<len;i++)
	{
		printf("%d, ",arr[i]);
	}
}