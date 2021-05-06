#include "binary_trees.h"

/**
 * binary_tree_node - Creates Binary Tree Node
 * @parent: Parent Node
 * @value: Value for new node.
 * Return: New node, nor NULL
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	return (node);
}