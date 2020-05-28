#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse - reverse linked list
 * @head_ref: pointer to the head reference
 *
 */
void reverse(listint_t **head_ref)
{
	listint_t *prev = NULL;
	listint_t *next;
	listint_t *current = *head_ref;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

/**
 * compareLists - check if two input lists have same data
 * @head1: pointer to one head
 * @head2: pointer to the other head
 * Return: 1 if they are equal, 0 if they are not equal
 */
int compareLists(listint_t *head1, listint_t *head2)
{
	listint_t *temp1 = head1;
	listint_t *temp2 = head2;

	if (temp1 == NULL && temp2 == NULL)
		return (1);
	while (temp1 && temp2)
	{
		if (temp1->n == temp2->n)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
			return (1);
		}
	}
	return (0);
}


/**
 * is_palindrome - check if the given linked list a palindrome or not
 * @head: pointer to head of list
 * Return: 1 if palindrome and 0 if not
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow_ptr = *head, *fast_ptr = *head;
	listint_t *second_half, *prev_of_slow_ptr = *head;
	listint_t *midnode = NULL;
	int result;

	if (*head == NULL)
		return (1);
	if (head != NULL && (*head)->next != NULL)
	{
		while (fast_ptr != NULL && fast_ptr->next != NULL)
		{
			fast_ptr = fast_ptr->next->next;
			prev_of_slow_ptr = slow_ptr;
			slow_ptr = slow_ptr->next;
		}
		if (fast_ptr != NULL)
		{
			midnode = slow_ptr;
			slow_ptr = slow_ptr->next;
		}
		second_half = slow_ptr;
		prev_of_slow_ptr->next = NULL;
		reverse(&second_half);
		result = compareLists(*head, second_half);
		reverse(&second_half);
		if (midnode != NULL)
		{
			prev_of_slow_ptr->next = midnode;
			midnode->next = second_half;
		}
		else
			prev_of_slow_ptr = second_half;
	}
	return (result);
}
