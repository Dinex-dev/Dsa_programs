#include <stdio.h>
#define seperator printf("\n******************************************\n");

int main()
{
	int size[2] = {0}, selected_arr = 0;

	for (int i = 1; i < 3; i++)
	{
		seperator
			printf("Enter the size of arr %d : ", i);
		scanf("%d", &size[i - 1]);
	}
	int arr1[size[0]], arr2[size[1]], *arr[] = {arr1, arr2};

	for (int i = 0; i < 2; i++)
	{
		seperator
			printf("Enter the default values for arr %d : ", i + 1);
		for (int j = 0; j < size[i]; j++)
			scanf("%d", &arr[i][j]);
	}
	while (1)
	{
		seperator
		printf("\nPlease enter Valid Information \n");
		printf("0.Exit  \t1.Insertion !!! (will delete last value from the arr)\n");
		printf("2.Deletion\t3.Traversal\n");
		printf("4.Revarsal\t5.Merge !!(temporary merge)\n");
		printf("Select one of the above operation :");
		int operator= 0;
		scanf("%d", &operator);
		if (!operator)
			return 0;
		seperator if (!(operator> 4))
		{
			printf("\n1. Array1\n2. Array2 \nselect one arr : ");
			scanf("%d", &selected_arr);
			if (!(selected_arr == 1 || selected_arr == 2))
				continue;
			--selected_arr;
		}
		seperator int arr3[size[0] + size[1]];
		switch (operator)
		{
		case 1:
			printf("Postition to insert element : ");
			int pos, value;
			scanf("%d", &pos);
			seperator
				printf("Value to be inserted : ");
			scanf("%d", &value);
			for (int i = 0; i < size[selected_arr] - pos + 1; i++)
				arr[selected_arr][size[selected_arr] - i] = arr[selected_arr][size[selected_arr] - i - 1];
			arr[selected_arr][pos - 1] = value;
			break;
		case 2:
			printf("\nWhich index do you want to delete : ");
			int del;
			scanf("%d", &del);
			for (int i = del - 1; i < size[selected_arr] - 1; i++)
				arr[selected_arr][i] = arr[selected_arr][i + 1];
			arr[selected_arr][size[selected_arr] - 1] = 0;
			break;
		case 3:
			printf("Array %d : \n", selected_arr+1);
			for (int i = 0; i < size[selected_arr]; i++)
				printf("%d\t", arr[selected_arr][i]);
			break;
		case 4:
			for (int i = 0; i < size[selected_arr] / 2; ++i)
			{
				int temp = arr[selected_arr][i];
				arr[selected_arr][i] = arr[selected_arr][size[selected_arr] - i - 1];
				arr[selected_arr][size[selected_arr] - i - 1] = temp;
			}
			break;
		case 5:
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < size[i]; j++)
					arr3[i * size[i] + j] = arr[i][j];
			for (int i = 0; i < size[0] + size[1] - 1; i++)
				printf("%d\t", arr3[i]);
			break;
		default:
			printf("Invalid choice\n");
			break;
		}
	}
}