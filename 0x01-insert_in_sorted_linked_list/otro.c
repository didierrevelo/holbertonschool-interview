#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer to pointer of head node 
 * @number: number to insert
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *actual;

	actual = *head;
	new = malloc(sizeof(listint_t));
	if (new)
	{
		new->n = number;
		new->next = NULL;

		if (*head == NULL || actual->n >= new->n)
		{
			new->next = *head;
			*head = new;
		}
		else
		{
			while (actual->next != NULL && actual->next->n < new->n)
			{
				actual = actual->next;
			}
			new->next = actual->next;
			actual->next = new;
		}
		return (new);
	}
	return (NULL);
}