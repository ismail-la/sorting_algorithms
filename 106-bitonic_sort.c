#include "sort.h"

void bitonic_sort(int *array, size_t size);
void swap_ints(int *a, int *b);
void Merge_Bitonic(int *array, size_t size, size_t start, size_t rang,
		char flow);
void Seq_Bitonic(int *array, int size, size_t start, int rang, char flow);


/**
 * swap_ints - Swap two integers in an array.
 * @a: First integer to swap.
 * @b: The second integer to swap.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * Merge_Bitonic - Function that sort a bitonic sequence inside an array of integers.
 * @start: Starting index of the sequence in array to sort
 * @rang: Size of the sequence to sort
 * @flow: The irection to sort
 * @array: Array of integers
 * @size: Size of the array in
 */

void Merge_Bitonic(int *array, size_t size, size_t start, size_t rang,
		char flow)
{
	size_t i, Jump = rang / 2;

	if (rang > 1)
	{
		for (i = start; i < start + Jump; i++)
		{
			if ((flow == UP && array[i] > array[i + Jump]) ||
			    (flow == DOWN && array[i] < array[i + Jump]))
				swap_ints(array + i, array + i + Jump);
		}
		Merge_Bitonic(array, size, start, Jump, flow);
		Merge_Bitonic(array, size, start + Jump, Jump, flow);
	}

}

/**
 * Seq_Bitonic - Converts an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @rang: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */

void Seq_Bitonic(int *array, int size, size_t start, int rang, char flow)
{
	size_t cut = rang / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (rang > 1)
	{
		printf("Merging [%i/%i] (%s):\n", rang, size, str);
		print_array(array + start, rang);

		Seq_Bitonic(array, size, start, cut, UP);
		Seq_Bitonic(array, size, start + cut, cut, DOWN);
		Merge_Bitonic(array, size, start, rang, flow);

		printf("Result [%i/%i] (%s):\n", rang, size, str);
		print_array(array + start, rang);
	}
}

/**
 * bitonic_sort - Sort an array of integers using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	Seq_Bitonic(array, size, 0, size, UP);
}
