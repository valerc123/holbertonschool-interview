#include "binary_trees.h"

/**
* sorted_array_to_avl - create the tree
* @array: to be converted
* @size: of array
* Return: sorted array
*/

avl_t *sorted_array_to_avl(int *array, size_t size)
{
    avl_t *h = NULL;

	if (array == NULL)
		return (NULL);
	if (is_tree_valid_avl(array, 0, (int)size - 1, &h) == NULL)
		return (NULL);
	return (h);
}

/**
 * is_tree_valid_avl - function that builds an AVL tree from an array
 * @array: to be converted
 * @p_start: start node
 * @p_end: end node
 * @h: header of node
 * Return: h
*/

avl_t *is_tree_valid_avl(int *array, int p_start, int p_end, avl_t **h)
{
	int index = 0;
	avl_t *left = NULL, *right = NULL, *new_n = NULL;

	if (p_start > p_end)
		return (NULL);
	index = (p_end + p_start) / 2;
	is_tree_valid_avl(array, p_start, index - 1, &left);
	is_tree_valid_avl(array, index + 1, p_end, &right);
	new_n = malloc(sizeof(avl_t));
	if (new_n == NULL)
		return (NULL);
	new_n->n = array[index];
	new_n->parent = NULL;
	new_n->left = left;
	new_n->right = right;
	if (left != NULL)
		left->parent = new_n;
	if (right != NULL)
		right->parent = new_n;
	*h = new_n;
	return (new_n);
}
