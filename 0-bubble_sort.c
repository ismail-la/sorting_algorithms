#include "sort.h"

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
 * bubble_sort - It Sort an array of integers in ascending order
 * @array: Array of integers to sort
 * @size: Size of the array
 *
 * Description: Prints the array after each swap
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, Vol = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < Vol - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				Swap2Int(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		Vol--;
	}
}
