#include "binary_trees.h"

/**
 * move_node - Moves nodes down tree
 * @node: Node to move
 *
 * Return: Void
 */

void move_node(heap_t *node)
{
	heap_t *largest = NULL;
	int aux;

	if (node->right)
	{
		if (node->right->n > node->left->n)
			largest = node->right;
		else
			largest = node->left;
	}
	else if (node->left)
		largest = node->left;
	if (largest && largest->n > node->n)
	{
		aux = largest->n;
		largest->n = node->n;
		node->n = aux;
		move_node(largest);
	}
}

/**
 * get_height - Finds the max depth of the tree, levels
 * @node: Root node of tree
 *
 * Return: Depth or levels of the tree
 */

int get_height(heap_t *node)
{
	int l, r;

	if (!node)
		return (0);
	l = get_height(node->left);
	r = get_height(node->right);
	if (l > r)
		return (l + 1);
	return (r + 1);
}

/**
 * get_last_node - Gets the last right node of the tree
 * @height: Depth of the tree
 * @rec_height: Counter for recursive height value
 * @node: Node
 *
 * Return: Last node
 */

heap_t *get_last_node(int height, int rec_height, heap_t *node)
{
	heap_t *left;
	heap_t *right;

	if (rec_height != height)
	{
		left = get_last_node(height, rec_height + 1, node->left);
		right = get_last_node(height, rec_height + 1, node->right);
	}
	else
		return (node);
	if (right)
		return (right);
	return (left);
}

/**
 * get_last - Finds last node of the tree
 * @root: Root node of the tree
 * Return: Last node
 */

heap_t *get_last(heap_t *root)
{
	int height;

	height = get_height(root);
	return (get_last_node(height, 1, root));
}

/**
 * heap_extract - Extracts root node of Max Binary Heap
 * @root: Double pointer to root node of heap
 * Return: 0 on fail or value stored in root node
 */

int heap_extract(heap_t **root)
{
	heap_t *aux;
	int swap;

	if (!*root)
		return (0);
	if (!(*root)->left && !(*root)->right)
	{
		swap = (*root)->n;
		free(*root);
		*root = NULL;
		return (swap);
	}
	aux = get_last(*root);
	if (aux->parent->right)
		aux->parent->right = NULL;
	else
		aux->parent->left = NULL;
	swap = (*root)->n;
	(*root)->n = aux->n;
	move_node(*root);
	free(aux);
	return (swap);
}
