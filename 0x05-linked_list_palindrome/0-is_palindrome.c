#include "lists.h"
/**
 * rescuePalindrome - checks if singly linked list is palindrome
 * @left: pointer to head of singly linked list
 * @right: head of singly linked list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int rescuePalindrome(listint_t **left, listint_t *right)
{
	int ret;

	if (right == NULL)
		return (1);

	ret = rescuePalindrome(left, right->next);
	if (ret == 0)
		return (0);

	ret = (right->n == (*left)->n);

	*left = (*left)->next;

	return (ret);
}
/**
 * is_palindrome - checks if singly linked list is palindrome
 * @head: pointer to head of singly linked list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	if (!head)
		return (0);
	return (rescuePalindrome(head, *head));
}
