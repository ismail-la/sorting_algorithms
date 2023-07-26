#include "sort.h"

void quick_sort_hoare(int *array, size_t size);
void Swap2Int(int *a, int *b);
int hoare_partition(int *array, size_t size, int First, int Last);
void Qs_Hoare(int *array, size_t size, int First, int Last);


/**
 * Swap2Int - It swap two integers in an array
 * @a: First integer to swap
 * @b: Second integer to swap
 */

void Swap2Int(int *a, int *b)
{
	int cmd;

	cmd = *a;
	*a = *b;
	*b = cmd;
}

/**
 * hoare_partition - Function that orders a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: Array of integers
 * @size: Size of the array
 * @First: Starting index of the subset to order
 * @Last: Ending index of the subset to order
 *
 * Return: Final partition index - return the position of the last element
 * sorted
 *
 * Description: It ses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */

int hoare_partition(int *array, size_t size, int First, int Last)
{
	int pivot, above, below;

	pivot = array[Last];

	for (above = First - 1, below = Last + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			Swap2Int(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * Qs_Hoare - Function that implements the quicksort algorithm through
 * recursion.
 * @First: Starting index of the array partition to order
 * @Last: Ending index of the array partition to order
 * @array: Array of integers to sort
 * @size: Size of the array
 *
 * Description: It uses the Hoare partition scheme.
 */

void Qs_Hoare(int *array, size_t size, int First, int Last)
{
	int rang;

	if (Last - First > 0)
	{
		rang = hoare_partition(array, size, First, Last);
		Qs_Hoare(array, size, First, rang - 1);
		Qs_Hoare(array, size, rang, Last);
	}

}

/**
 * quick_sort_hoare - Function that sort an array of integers in ascending
 *                    order using the Quick sort algorithm.
 * @array: Array of integers
 * @size: Size of the array
 *
 * Description: It uses the Hoare partition scheme.
 * Prints the array after each swap of two elements
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	Qs_Hoare(array, size, 0, size - 1);
}
