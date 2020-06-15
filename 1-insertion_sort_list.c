#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order
 *
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous;

	if (!list || !*list)
		return;

	current = *list;

	while (current)
	{
		while (current->prev && current->n < current->prev->n)
		{
			current->prev->next = current->next;
			previous = current->prev;
			if (current->next)
				current->next->prev = previous;
			if (previous->prev)
				previous->prev->next = current;
			else
				*list = current;
			previous->next = current->next;
			current->prev = previous->prev;
			current->next = previous;
			previous->prev = current;

			print_list(*list);
		}

		current = current->next;
	}
}
