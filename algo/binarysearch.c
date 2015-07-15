//binary search
 #include <stdio.h>

int searchelement(int array[], int left, int right, int key)
{
	int mid;
	mid = (left + right + 1)/2;

	if (left >= right)
	{
		printf("Not Found. :(\n");
		return;
	}
	if (array[mid] == key)
	{
		printf("Found. :)\n");
		return;
	}
	else if (key < array[mid])
	{
		right = mid;
		searchelement(array,left,right,key);
	}
	else
	{
		left = mid;
		searchelement(array,left,right,key);
	}

}

int main(int argc, char const *argv[])
{
	/* code */
	int array[100], i, left, right, key;
	int numofelement;

	printf("Enter number of element in array:\n");
	scanf("%d",&numofelement);
	printf("Enter element of array:\n");
	for (i = 0; i < numofelement; ++i)
	{
		scanf("%d",&array[i]);
	}

	printf("elements of array:\n");
	for (i = 0; i < numofelement; ++i)
	{
		printf("%d\n",array[i]);
	}
	printf("Enter element to search:\n");
	scanf("%d",&key);

	left = 0;
	right = numofelement - 1;

	searchelement(array, left, right, key);

	return 0;
}