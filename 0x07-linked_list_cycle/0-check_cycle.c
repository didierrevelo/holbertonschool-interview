#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has
 *  a cycle in it
 * @list: head of linked list
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{

	listint_t *runner, *way;

	if (!list)
		return (0);

	runner = list;
	way = list;

	while (runner && way && way->next)
	{
		runner = runner->next;
		way = way->next->next;

		if (way == runner)
			return (1);
	}

	return (0);
}