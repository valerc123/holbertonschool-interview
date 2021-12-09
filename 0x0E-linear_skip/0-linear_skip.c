#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the list
 * @value: Ponter on the first node where value is located
 *
 * Return: pointer on success or NULL
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp, *prev;

	if (!list)
		return (NULL);
	tmp = list->express;
	prev = list;
	while (tmp)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       tmp->index, tmp->n);
		if (!tmp->express || tmp->n >= value)
		{
			if (!tmp->express && tmp->n < value)
			{
				prev = tmp;
				while (tmp->next)
					tmp = tmp->next;
			}
			printf("Value found between indexes [%lu] and [%lu]\n",
			       prev->index, tmp->index);
			while (prev)
			{
				printf("Value checked at index [%lu] = [%d]\n",
				       prev->index, prev->n);
				if (prev->n > value)
					return (NULL);
				if (prev->n == value)
					return (prev);
				prev = prev->next;
			}
			break;
		}
		prev = tmp;
		tmp = tmp->express;
	}
	return (NULL);
}
