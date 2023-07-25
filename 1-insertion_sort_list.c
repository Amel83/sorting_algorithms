#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sorts in isertion sort
 * @list: doubly linked list struct
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *p, *temp;

	if (!list)
		return;

	p = *list;

	while (p)
	{
		while (p->next && (pr->n > p->next->n))
		{
			temp = p->next;
			p->next = temp->next;
			temp->prev = p->prev;

			if (p->prev)
				p->prev->next = temp;

			if (temp->next)
				temp->next->prev = p;

			p->prev = temp;
			temp->next = p;

			if (t->prev)
				p = temp->prev;
			else
				*list = temp;

			print_list(*list);
		}
		p = p->next;
	}
}
