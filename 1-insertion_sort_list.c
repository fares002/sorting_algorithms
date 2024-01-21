#include "sort.h"
/**
 * swapping - swap two node
 * @x: first node
 * @y: second node
 * Return: void
 */
void swapping(listint_t *x, listint_t *y)
{
	if (x->prev)
		x->prev->next = y;
	if (y->next)
		y->next->prev = x;
	x->next = y->next;
	y->prev = x->prev;
	x->prev = y;
	y->next = x;
}
/**
 * insertion_sort_list - insertion sort
 * @list: list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *x, *y;

	if (!list || !*list || !(*list)->next)
		return;
	x = (*list)->next;
	while (x != NULL)
	{
		y = x;
		x = x->next;
		while (y && y->prev)
		{
			if (y->prev->n > y->n)
			{
				swapping(y->prev, y);
				if (y->prev == NULL)
					*list = y;
				print_list((const listint_t *)*list);
			}
			else
				y = y->prev;
		}
	}
}
