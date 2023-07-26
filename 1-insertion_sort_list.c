#include "sort.h"

/**
 * Swap2Nodes - It Swap two nodes in a listint_t doubly-linked list
 * @h: Pointer to the head of the doubly-linked list
 * @n1: Pointer to the first node to swap
 * @n2: Second node to swap
 */

void Swap2Nodes(listint_t **h, listint_t **n1, listint_t *n2)
{

	(*n1)->next = n2->next;

	if (n2->next != NULL)
		n2->next->prev = *n1;

	n2->prev = (*n1)->prev;
	n2->next = *n1;

	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;

}

/**
 * insertion_sort_list - Fonction that Sorts a doubly linked
 * list of integers in ascending order.
 * @list: Pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */

void insertion_sort_list(listint_t **list)
{

	listint_t *tmp, *Rep, *insert;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (Rep = (*list)->next; Rep != NULL; Rep = tmp)
	{
		tmp = Rep->next;
		insert = Rep->prev;

		while (insert != NULL && Rep->n < insert->n)
		{
			Swap2Nodes(list, &insert, Rep);
			print_list((const listint_t *)*list);
		}
	}

}
