#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a singly linkend list
 * @head: pointer to head of list
 * @number: data of the new node
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{

	listint_t *current;
	listint_t *new_node;

	current = *head;
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = number;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else if (current->n > number)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		while (current->next != NULL && current->next->n < new_node->n)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}

	return (new_node);
}
