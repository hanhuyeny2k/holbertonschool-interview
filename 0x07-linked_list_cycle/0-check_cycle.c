#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - checks if the singly linked list has a cycle in it
 * @list: pointer to head of list
 * Return: 0 if there is no cycle, else return 1
 */

int check_cycle(listint_t *list)
{
	listint_t *slow_p = list;
	listint_t *fast_p = list;

	while (slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p)
			return (1);
	}
	return (0);
}
