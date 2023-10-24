#include "sort.h"
<<<<<<< HEAD
/**
 * insertion_sort_list - sort a double linked list
 * @list: a pointer to a double linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *node, *tmp;

	if (!list || !(*list))
		return;
	head = node = *list;
	while (node)
	{
		if (!node->prev)
		{
			node = node->next;
			continue;
		}
		else if (node->n < node->prev->n)
		{
			tmp = node->prev;
			tmp->next = node->next;
			if (node->next)
				node->next->prev = tmp;
			node->next = tmp;
			node->prev = tmp->prev;
			tmp->prev = node;
			if (node->prev)
				node->prev->next = node;
			else
			{
				node->prev = NULL;
				head = node;
			}
			print_list(head);
		}
		else if (node->n >= node->prev->n && !node->next)
		{
			*list = head;
			return;
		}
		else
		{
			node = node->next;
		}
=======

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
>>>>>>> 3cf4cd57a1fb6a15897307d3cddd13d233f2ed9d
	}
}
