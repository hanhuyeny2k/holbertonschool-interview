#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * heap_size - Find the size of the binary tree
 *
 * @root: Pointer to the root
 *
 * Return: Size of the binary tree
 */

size_t heap_size(const heap_t *root)
{
	if (root != NULL)
		return (heap_size(root->left) + heap_size(root->right) + 1);
	return (0);
}

/**
 * enqueue - enqueue a heap node pointer
 *
 * @rear: Pointer to the last element in a queue
 * @node: The node to add to the queue
 *
 * Return: A pointer to the new last element
 */
heap_t **enqueue(heap_t **rear, heap_t *node)
{
	*rear = node;
	return (rear + 1);
}


/**
 * dequeue - dequeue a heap node pointer
 *
 * @front: Pointer to the first element in a queue
 *
 * Return: Pointer to the new first element
 */
heap_t **dequeue(heap_t **front)
{
	return (front + 1);
}

/**
 * swap_int - entry point
 * @a: parameter of a digit
 * @b: parameter of a digit
 *
 * Description: swap integers
 */
void swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}


/**
 * _heap_insert - to enqueue and dequeue the binary tree
 * @root: pointer to root of binary tree
 * @queue: pointer to the beginnig of the queue
 * @new_node: pointer to the new node created
 *
 */
void _heap_insert(heap_t **root, heap_t **queue, heap_t *new_node)
{
	heap_t **front = NULL, **rear = NULL;

	front = rear = queue;
	rear = enqueue(rear, *root);
	while (front != rear)
	{
		if ((*front)->left != NULL)
			rear = enqueue(rear, (*front)->left);
		else
		{
			(*front)->left = new_node;
			new_node->parent = *front;
			break;
		}
		if ((*front)->right != NULL)
			rear = enqueue(rear, (*front)->right);
		else
		{
			(*front)->right = new_node;
			new_node->parent = *front;
			break;
		}
		front = dequeue(front);
	}
}
