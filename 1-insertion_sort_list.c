#include "sort.h"

/**
 * swap_node - swap the nodes in a double linked list of integers
 *
 * @left: pointer to a current node.
 * @right: pointer to the next node
 * @head: pointer to the head of a double linked list
 * Return: nothing.
 */

void swap_node(listint_t **head, listint_t *left, listint_t *right)
{
	listint_t *temp1, *temp2;

	if (left == NULL || right == NULL)
	{
		return;
	}

	temp1 = left->prev;
	temp2 = right->next;

	if (temp1)
	{
		temp1->next = right;
	}

	if (temp2)
	{
		temp2->prev = left;
	}

	left->next = temp2;
	left->prev = right;
	right->next = left;
	right->prev = temp1;

	if (temp1 == NULL)
	{
		*head = right;
	}
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
	listint_t *current, *prev;

	current = (*list);

	if (current == NULL || current->next == NULL)
	{
		return;
	}

	while (current)
	{
		prev = current->prev;
		while ((prev) && (current->n < prev->n))
		{
			swap_node(list, prev, current);
			print_list(*list);
			prev = current->prev;
		}
		current = current->next;
	}
}
