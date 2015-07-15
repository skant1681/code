// merge sort

#include <stdio.h>

void merge(int array[], int left, int right, int mid)
{
	int i, j, k;
	int n1 = mid - left;
	int n2 = right - mid + 1;
	int Larr[n1], Rarr[n2];

	for (i = 0; i < n1; i++)
		Larr[i] = array[left + i];

	for (i = 0; i < n2; i++)
		Rarr[i] = array[mid + i];
	

	i = 0;
	j = 0;
	k = left;


	while(i < n1 && j < n2)
	{
		if(Larr[i] >= Rarr[j])
		{
			array[k] = Rarr[j];
			j++;
			k++;
		}
		else
		{
			array[k] = Larr[i];
			i++;
			k++;
		}
	}

	while(i < n1)
	{
		array[k] = Larr[i];
		i++;
		k++;
	}

	while(j < n2)
	{
		array[k] = Rarr[j];
		j++;
		k++;
	}
}

void mergesort(int array[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right + 1)/2;
		mergesort(array, left, mid - 1 );
		mergesort(array, mid, right);
		merge(array, left, right, mid);
	}
}

int main(int argc, char const *argv[])
{
	int array[100], i;
	int numofelement;
	int left, right, mid;

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

	left = 0;
	right = numofelement - 1;
	
	mergesort(array, left, right);
	
	for (i = 0; i < numofelement; i++)
	{
		printf("%d\n",array[i]);
	}

	return 0;
}