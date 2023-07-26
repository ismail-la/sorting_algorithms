#include "sort.h"

void merge_sort(int *array, size_t size);
void Merge_SubAr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void Merge_order_recursive(int *subarr, int *buff, size_t front, size_t back);

/**
 * Merge_order_recursive - Function that implement the merge sort algorithm through recursion
 * @front: Front index of the subarray
 * @back: Back index of the subarray
 * @subarr: Subarray of an array of integers to sort
 * @buff: Buffer to store the sorted result
 */

void Merge_order_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		Merge_order_recursive(subarr, buff, front, mid);
		Merge_order_recursive(subarr, buff, mid, back);
		Merge_SubAr(subarr, buff, front, mid, back);
	}
}

/**
 * Merge_SubAr - Function that sort a subarray of integers
 * @front: Front index of the array
 * @mid: Middle index of the array
 * @back: Back index of the array
 * @subarr: Subarray of an array of integers to sort
 * @buff: Buffer to store the ordered subarray
 */

void Merge_SubAr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t b = 0, i, j;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; b++)
		buff[b] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[b++] = subarr[i];
	for (; j < back; j++)
		buff[b++] = subarr[j];
	for (i = front, b = 0; i < back; i++)
		subarr[i] = buff[b++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}


/**
 * merge_sort - Function that sort an array of integers in ascending
 *              order using the merge sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 *
 * Description: It implements the top-down merge sort algorithm.
 */

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	Merge_order_recursive(array, buff, 0, size);

	free(buff);
}
