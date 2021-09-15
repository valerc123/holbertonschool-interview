#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: head of a singly linked list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	return (checkPalindrome(head, *head));
}
int checkPalindrome(listint_t **left, listint_t *right)
{
	int result;

	if (right == NULL)
		return (1);

	result = checkPalindrome(left, right->next) &&
			((*left)->n == right->n);
	(*left) = (*left)->next;

	return (result);
}
