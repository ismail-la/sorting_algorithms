#include "sort.h"

void heap_sort(int *array, size_t size);
void Swap2Int(int *a, int *b);
void Max_Heap(int *array, size_t size, size_t base, size_t root);


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
 * Max_Heap - Function that turn a binary tree into a complete binary heap
 * @base: Index of the base row of the tree
 * @root: Root node of the binary tree (heap)
 * @array: Array of integers representing a binary tree
 * @size: Size of the array / tree
 */

void Max_Heap(int *array, size_t size, size_t base, size_t root)
{
	size_t Right, Left, Big;

	Right = 2 * root + 2;
	Left = 2 * root + 1;
	Big = root;

	if (Left < base && array[Left] > array[Big])
		Big = Left;
	if (Right < base && array[Right] > array[Big])
		Big = Right;

	if (Big != root)
	{
		Swap2Int(array + root, array + Big);
		print_array(array, size);
		Max_Heap(array, size, base, Big);
	}

}

/**
 * heap_sort - Function that sort an array of integers in ascending
 *             order with the Heap sort algorithm
 * @size: Size of the array
 * @array: Array of integers
 *
 * Description: It implements the sift-down heap sort algorithm.
 * Prints the array after each swap.
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		Max_Heap(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		Swap2Int(array, array + i);
		print_array(array, size);
		Max_Heap(array, size, i, 0);
	}

}
