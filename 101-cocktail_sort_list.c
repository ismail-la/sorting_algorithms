#include "sort.h"

void cocktail_sort_list(listint_t **list);
void Swap_Prev_node(listint_t **list, listint_t **tail, listint_t **shaker);
void Swap_Next_node(listint_t **list, listint_t **tail, listint_t **shaker);


/**
 * Swap_Next_node - Function that swap a node in a listint_t doubly-linked list
 * list of integers with the node Next of it
 * @shaker: Pointer to the current swapping node of the cocktail shaker algo
 * @tail: Pointer to the tail of the doubly-linked list
 * @list: Pointer to the head of a doubly-linked list of integers
 */

void Swap_Next_node(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;

	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * Swap_Prev_node - Function that swap a node in a listint_t doubly-linked
 * list of integers with the node Previous it
 * @shaker: Pointer to the current swapping node of the cocktail shaker algo
 * @list: Pointer to the head of a doubly-linked list of integers
 * @tail: Pointer to the tail of the doubly-linked list
 */

void Swap_Prev_node(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;

	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}

/**
 * cocktail_sort_list -Rearrange or sorts a doubly-linked list of integers,
 * implemented as a listint_t, in ascending order using the cocktail shaker
 * sort algorithm.
 * @list: Pointer to the head of a listint_t doubly-linked list
 */

void cocktail_sort_list(listint_t **list)
{
	bool shaken_not_whiskered = false;
	listint_t *shaker, *tail;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_whiskered == false)
	{
		shaken_not_whiskered = true;

		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				Swap_Next_node(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_whiskered = false;
			}
		}

		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				Swap_Prev_node(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_whiskered = false;
			}
		}
	}

}
