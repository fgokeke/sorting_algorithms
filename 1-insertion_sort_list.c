#include "sort.h"

/**
 * insertion_sort_list -  a function that sorts a doubly linked
 * list of integers in ascending order using
 * the Insertion sort algorithm.
 * @list: the list to be sorted.
 *
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;
		prev =  current->prev;
		while (prev != NULL && prev->n > current->n)
		{
			if (prev->prev)
				prev->prev->next = current;
			else
				*list = current;
			if (current->next)
				current->next->prev = prev;
			prev->next = current->next;
			current->prev = prev->prev;
			current->next = prev;
			prev->prev = current;
			print_list(*list);
			prev = current->prev;
		}
		current = next;
	}
}
