
#include <stdio.h>

void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void insertionsort(int array[], int numofelement)
{
	int i,j;
	for (i = 1; i < numofelement; i++)
	{
			j = i - 1;
			while(j >= 0)
			{
				if(array[j] > array[j+1])
				{
					swap(&array[j], &array[j+1]);
					j = j - 1;
				}
				else
					break;
			}
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
	
	insertionsort(array, numofelement);
	
	for (i = 0; i < numofelement; i++)
	{
		printf("%d\n",array[i]);
	}

	return 0;
}