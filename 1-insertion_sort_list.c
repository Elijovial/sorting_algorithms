#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return; /* no need to sort if list is empty or has one node */

	current = (*list)->next; /* start from the second node */
	while (current != NULL)
	{
		prev = current->prev; /* keep track of the previous node */
		while (prev != NULL && prev->n > current->n) /* compare values */
		{
			/* swap nodes */
			prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev;
			current->prev = prev->prev;
			current->next = prev;
			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current; /* update head of list */
			prev->prev = current;

			print_list(*list); /* print list after each swap */

			prev = current->prev; /* update previous node */
		}
		current = current->next; /* move to next node */
	}
}

