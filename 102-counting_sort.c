#include "sort.h"

/**
 * Get_maximum - Get the maximum value in an array of integers
 * @size: Size of the array
 * @array: Array of integers
 *
 * Return: The maximum integer in the array
 */

int Get_maximum(int *array, int size)
{
	int i, max;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - Function that sort an array of integers in ascending order
 *                 using the counting sort algorithm
 * @size: Size of the array
 * @array: Array of integers
 *
 * Description: It prints the counting array after setting it up
 */
void counting_sort(int *array, size_t size)
{
	int *Count, *ordered;
	int max, i;

	if (array == NULL || size < 2)
		return;

	ordered = malloc(sizeof(int) * size);

	if (ordered == NULL)
		return;
	max = Get_maximum(array, size);
	Count = malloc(sizeof(int) * (max + 1));

	if (Count == NULL)
	{
		free(ordered);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		Count[i] = 0;
	for (i = 0; i < (int)size; i++)
		Count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		Count[i] += Count[i - 1];
	print_array(Count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		ordered[Count[array[i]] - 1] = array[i];
		Count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = ordered[i];

	free(ordered);
	free(Count);

}
