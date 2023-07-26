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
 * shell_sort - Fonction that sort an array of integers in ascending
 *              order using the shell sort algorithm (with Knuth sequence)
 * @size: Size of the array - Size of the array
 * @array: Array of integers - list with numbers
 *
 * Description: Uses the Knuth interval sequence
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, j, i;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				Swap2Int(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}

}
