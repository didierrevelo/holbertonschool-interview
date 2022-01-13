#include "lists.h"
#include <stdio.h>
/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: pointer to the head in linked list to test
 *
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *p1, *p2;

	if (head == NULL)
	return (NULL);
	p1 = head;
	p2 = head;
	while (p2 && p2->next)
	{
		p1 = p1->next;
		p2 = p2->next->next;
		if (p1 == p2)
		{
			p1 = head;
			while (p1 != p2)
			{
				p1 = p1->next;
				p2 = p2->next;
			}
			return (p1);
			}
		}
	return (NULL);
}
