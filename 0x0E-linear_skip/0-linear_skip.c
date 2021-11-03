#include "search.h"
/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: Pointer on the first node where value is located or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list;
	skiplist_t *express_lane = list;
	size_t i = 0;

	if (!list)
		return (NULL);


	while (current && current->next && (current->n) < value)
	{
		express_lane = current;
		if (current->express)
		{
			current = current->express;
			printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
		}
		else
		{
			while (current->next)
			{
				current = current->next;
			}
		}
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
					 express_lane->index, current->index);

	for (i = express_lane->index;
					 i <= (current->index) && (express_lane->n <= value);
					 i++, express_lane = express_lane->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", i, express_lane->n);
		if (express_lane && (express_lane->n) == value)
			return (express_lane);
	}
	if (express_lane)
	{
		printf("Value checked at index [%lu] = [%d]\n", i, express_lane->n);
	}
	return (NULL);
}
