// BUBBLE SORT Time complexity: worst case: O(n^2) average case: O(n^2) best case:  O(n)

#include <stdio.h>

void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void bubblesort(int array[], int numofelement)
{
	int i,j,k,tempnum;
	int flag;
	tempnum = numofelement;

	for (k = 0; k < numofelement; k++)
	{
		for (i = 0; i < tempnum - 1; i++)
		{
			j = i + 1;
			flag = 0;
			if (array[j] < array[i])
			{
				swap(&array[j],&array[i]);
				flag = 1;
			}
		}
		tempnum = tempnum - 1;
		if (flag == 0)
			break;
	}
}

int main(int argc, char const *argv[])
{
	int array[100], i;
	int numofelement;

	printf("Enter number of element in array:\n");
	scanf("%d",&numofelement);

	printf("Enter element of array:\n");
	for (i = 0; i < numofelement; i++)
	{
		scanf("%d",&array[i]);
	}

	printf("elements of array: before sorting\n");
	for (i = 0; i < numofelement; i++)
	{
		printf("%d\n",array[i]);
	}

	printf("elements of array: after sorting\n");
	bubblesort(array, numofelement);
	for (i = 0; i < numofelement; i++)
	{
		printf("%d\n",array[i]);
	}

	return 0;
}