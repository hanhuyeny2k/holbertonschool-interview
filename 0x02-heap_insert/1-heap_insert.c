#include "binary_trees.h"
#include <stdlib.h>

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
	free(queue);
	swap_int (&new_node->n, &new_node->parent->n);
	return (new_node);
}
