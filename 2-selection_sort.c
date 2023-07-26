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
 * selection_sort - Fonction that sort an array of integers in
 * ascending order
 * @size: Size of the array
 * @array: Array of integers - list with numbers
 * Description: It Prints the array after each swap
 */

void selection_sort(int *array, size_t size)
{
	size_t j, i;
	int *Less;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		Less = array + i;
		for (j = i + 1; j < size; j++)
			Less = (array[j] < *Less) ? (array + j) : Less;

		if ((array + i) != Less)
		{
			Swap2Int(array + i, Less);
			print_array(array, size);
		}
	}

}
