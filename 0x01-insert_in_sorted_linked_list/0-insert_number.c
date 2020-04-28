#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - insert a number into a sorted linked list
 * @number: integer within the node
 * @head: double pointer pointing to the first node
 *
 * Return: the address of the new node, or Null if failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *ptr;
	listint_t *prev = NULL;
	listint_t *new_node;

	if (head == NULL)
		return (NULL);
	ptr = *head;
	if (ptr == NULL)
		return (NULL);
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = number;

	if (*head == NULL || number < ptr->n)
	{
		new_node->n = number;
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	for (; ptr != NULL && ptr->n < number; ptr = ptr->next)
		prev = ptr;
	new_node->next = ptr;
	prev->next = new_node;
	return (new_node);
}
