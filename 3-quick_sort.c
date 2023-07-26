#include "sort.h"

void Swap2Int(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void Lomuto_QS(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - sorting scheme implementation
 * of integers according to the lomuto partition scheme
 * @array: Array of integers
 * @left: Starting index of the subset to order - first element
 * @right: Ending index of the subset to order - last element
 * @size: Size of the array
 *
 * Return: Final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, less, over;

	pivot = array + right;

	for (over = less = left; less < right; less++)
	{
		if (array[less] < *pivot)
		{
			if (over < less)
			{
				Swap2Int(array + less, array + over);
				print_array(array, size);
			}
			over++;
		}
	}

	if (array[over] > *pivot)
	{
		Swap2Int(array + over, pivot);
		print_array(array, size);
	}

	return (over);
}

/**
 * Lomuto_QS - Implement the quicksort algorithm
 * @array: Array of integers to sort
 * @left: Starting index of the array partition to order - first array element
 * @right: Ending index of the array partition to order -  last array element
 * @size: Size of the array
 *
 * Description: It uses the Lomuto partition scheme
 */

void Lomuto_QS(int *array, size_t size, int left, int right)
{
	int Bit;

	if (right - left > 0)
	{
		Bit = lomuto_partition(array, size, left, right);
		Lomuto_QS(array, size, left, Bit - 1);
		Lomuto_QS(array, size, Bit + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order using
 * quicksort algorithm -  prepare the terrain to quicksort algorithm
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: It uses the Lomuto partition scheme. prints the array after
 * each swap of two elements.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	Lomuto_QS(array, size, 0, size - 1);
}
