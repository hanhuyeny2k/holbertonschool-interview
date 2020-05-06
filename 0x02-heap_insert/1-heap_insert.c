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

/**
 * heap_insert - function that insert a value into a Max Binary Heap
 *@root: a double pointer to the root node of the Heap
 *@value: the value store in the node to be inserted
 *
 * Return: a pointer to the inserted node, new_node
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL, **queue = NULL;

	size_t size = 0;

	if (root == NULL)
		return (NULL);
	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);
	size = heap_size(*root);
	if (size == 0)
	{
		*root = new_node;
		return (new_node);
	}
	queue = calloc(size, sizeof(heap_t *));
	if (queue == NULL)
	{
		free(new_node);
		return (NULL);
	}
	_heap_insert(root, queue, new_node);
	free(queue);
	while (new_node->parent != NULL && new_node->n > new_node->parent->n)
	{
		swap_int (&new_node->n, &new_node->parent->n);
		new_node = new_node->parent;
	}
	return (new_node);
}
