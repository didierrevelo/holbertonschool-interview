#include "lists.h"

/**
 * insert_node - is a funcyion that inserts
 * a number into a sorted singly linked list.
 * @head: pointer
 * @number: number
 * Return: number of nodes
 */


listint_t *insert_node(listint_t **head, int number)
{
	int runner;
	listint_t *new, *temp;

	temp = *head;
	new = malloc(sizeof(listint_t));
	if (new)
	{
		new->n = number;
		new->next = NULL;
		if (*head == NULL || temp->n >= new->n)
		{
			new->next = *head;
			*head = new;
			return (new);
		}
		else
		{
			for (runner = 0; temp->next != NULL && temp->next->n < new->n; runner++)
			{
				temp = temp->next;
			}
			new->next = temp->next;
			temp->next = new;
		}
		return (new);
	}
	free(new);
	return (NULL);
}
