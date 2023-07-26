#include "deck.h"

/**
 * sort_deck - Function that sorts a deck of card
 * @deck: a doubly linked list to sort
 */

void sort_deck(deck_node_t **deck)
{
	size_t Vol;
	deck_node_t *one, *two, *three, *four;
	deck_node_t *flow;

	Vol = Len_List_deck(*deck);

	if (!deck || !*deck || Vol < 2)
		return;

	flow = *deck;
	while (flow)
	{
		if (flow->prev && card_value(flow) < card_value(flow->prev))
		{
			one = flow->prev->prev;
			two = flow->prev;
			three = flow;
			four = flow->next;

			two->next = four;

			if (four)
				four->prev = two;
			three->next = two;
			three->prev = one;

			if (one)
				one->next = three;
			else
				*deck = three;
			two->prev = three;
			flow = *deck;
			continue;
		}
		else
			flow = flow->next;
	}

}

/**
 * card_value - Function that returns the value of a card
 * @node: The card in a deck
 *
 * Return: the value between 1 and 52
 */

int card_value(deck_node_t *node)
{
	char *val[13] = {"Ace", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen", "King"};
	char *kinds[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	int kind_val = 0, i;

	for (i = 1; i <= 13; i++)
	{
		if (!_strcmp(node->card->value, val[i - 1]))
			kind_val = i;
	}

	for (i = 1; i <= 4; i++)
	{
		if (!_strcmp(kinds[node->card->kind], kinds[i - 1]))
			kind_val = kind_val + (13 * i);
	}

	return (kind_val);

}

/**
 * _strcmp - Function that compares two strings
 * @s1: The first string to compare
 * @s2: The second string to compare
 *
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * Len_List_deck - function that returns length of list.
 * @list: The head of list.
 *
 * Return: The length
 */
size_t Len_List_deck(deck_node_t *list)
{
	size_t Vol = 0;

	while (list)
	{
		Vol++;
		list = list->next;
	}
	return (Vol);

}
