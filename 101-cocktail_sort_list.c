#include "sort.h"

/**
 * _swap - Swaps two nodes of doubly linked list
 *
 * @node: node base to change
 * @list: double link list head
 *
 * Return: No Return
 */
void _swap(listint_t **node, listint_t **list)
{
	listint_t *tmp = *node, *tmp2, *tmp3;


	if (!(*node)->prev)
		*list = (*node)->next;

	tmp = tmp3 = *node;
	tmp2 = tmp->next;

	tmp->next = tmp2->next;
	tmp3 = tmp->prev;
	tmp->prev = tmp2;
	tmp2->next = tmp;
	tmp2->prev = tmp3;

	if (tmp2->prev)
		tmp2->prev->next = tmp2;


	if (tmp->next)
		tmp->next->prev = tmp;

	*node = tmp2;

}
/**
 * cocktail_sort_list - function that sorts
 * @list: head of list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *h, *var;
	int i = 0, n = -1, m = -1;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	h = *list;
	while (m >= n)
	{
		n++;
		while (h->next && i != m)
		{
			if (h->n > h->next->n)
			{
				var = h;
			       _swap(&var, list);
			       print_list(*list);
			       h = var;
			}

			i++;
			h = h->next;
		}

		if (n == 0)
			m = i;
		m--;
		while (h->prev && i >= n)
		{
			if (h->n < h->prev->n)
			{
				var = h->prev;
				_swap(&var, list);
				print_list(*list);
				h = var->next;
			}
			i--;
			head = h->prev;
		}
	}
}
