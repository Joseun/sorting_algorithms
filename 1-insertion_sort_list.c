#include "sort.h"

/**
 * swap_node - swap the nodes in a double linked list of integers
 *
 * @node: pointer to a node doubly linked list.
 *
 * Return: nothing.
 */

void swap_node(listint_t *left, listint_t *right)
{
	listint_t *temp1, *temp2;

	temp1 = left->prev;
	temp2 = right->next;
	left->next = temp2;
	left->prev = right;
	right->next = left;
	right->prev = temp1;
	left->prev = right;
	temp1->next = right;
}

/**
 * swap_null - swap the nodes at the head in a double linked list of integers
 *
 * @node: pointer to a node doubly linked list.
 *
 * Return: nothing.
 */

void swap_null(listint_t **head, listint_t *current)
{
	listint_t *temp, *next;

	next = current->next;
	temp = next->next;
	current->next = temp;
	current->prev = next;
	next->next = current;
	next->prev = NULL;
	current->prev = next;
	*(head) = next;
}


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
	listint_t *current, *next, *prev, *left, *right;

	current = (*list);
	next = current->next;
	prev = current->prev;

	if (current == NULL)
	{
		return;
	}

	while (current)
	{
		if (prev == NULL)
		{
			if (current->n > next->n)
			{
				swap_null(list, current);
				print_list(*list);
			}
		}
		else
		{
			while (current)
			{
				if((next != NULL) && (current->n > next->n))
				{
					left = current;
					right = next;
 					swap_node(left, right);
					print_list(*list);
					left = next;

					while ((left->prev) && (left->n < left->prev->n))
					{
						swap_node(left->prev, left);
						print_list(*list);

						if (left->prev == NULL)
						{
							swap_null(list, prev->prev);
							print_list(*list);
						}
					}
				}
				else
				{
					current = current->next;
				}
			}
		}
	}
}
