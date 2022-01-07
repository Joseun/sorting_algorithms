#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order.
 *
 * @list: pointer to the doubly linked list.
 *
 * Return: nothing.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *prev;

	current = (*list);
	next = (*list)->next;
	prev = (*list)->prev;

	if (current == NULL)
	{
		return;
	}

	while (current)
	{
		if(current->n > next->n)
		{
			current->prev->next = next;
			next->prev = current->prev;
			current->next = next->next;

			if (next->next != NULL)
			{
				next->next->prev = current;
		       		current->prev = next;
				next->next = current;
			}
		}

		if (current->prev != NULL)
		{
			if(current->n < prev->n)
			{
				prev->prev->next = current;
				current->prev = prev->prev;
				prev->next = current->next;

				if (current->next != NULL)
				{
					current->next->prev = prev;
					prev->prev = current;
					current->next = prev;
				}
			}
		}
		current = current->next;
		next = next->next;
	}
	print_list(*list);
}
