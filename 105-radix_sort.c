#include "sort.h"

void radix_sort(int *array, size_t size);
int Get_maximum(int *array, int size);
void Radix_sort_count(int *array, size_t size, int Sig_digit, int *buff);


/**
 * Get_maximum - Function that get the maximum value in an array of integers
 * @array: Array of integers
 * @size: Size of the array
 *
 * Return: Maximum integer in the array
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
 * Radix_sort_count - Function that sort the significant digits of an array of integers
 *                    in ascending order using counting sort algorithm
 * @Sig_digit: Significant digit to sort on
 * @buff: Buffer to store the sorted array
 * @array: Array of integers
 * @size: Size of the array
 */
void Radix_sort_count(int *array, size_t size, int Sig_digit, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / Sig_digit) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / Sig_digit) % 10] - 1] = array[i];
		count[(array[i] / Sig_digit) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];

}

/**
 * radix_sort - Function that sort an array of integers in ascending
 *              order using the radix sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 *
 * Description: It implements the LSD radix sort algorithm.
 * Prints the array after each significant digit increase.
 */

void radix_sort(int *array, size_t size)
{
	int *buff, max, Sig_digit;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);

	if (buff == NULL)
		return;

	max = Get_maximum(array, size);

	for (Sig_digit = 1; max / Sig_digit > 0; Sig_digit *= 10)
	{
		Radix_sort_count(array, size, Sig_digit, buff);
		print_array(array, size);
	}

	free(buff);

}
