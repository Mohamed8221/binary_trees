#include "binary_trees.h"
#include <limits.h>

/**
* binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
* @tree: pointer to the root node of the tree to check
*
* Return: 1 if tree is a valid BST, and 0 otherwise. If tree is NULL, return 0.
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
return (bst_helper((binary_tree_t *)tree, INT_MIN, INT_MAX));
}

/**
* bst_helper - helper function for binary_tree_is_bst
* @tree: pointer to the root node of the tree to check
* @min: integer representing the "minimum" value of a node
* @max: integer representing the "maximum" value of a node
*
* Return: 1 if tree is a valid BST, and 0 otherwise
*/
int bst_helper(binary_tree_t *tree, int min, int max)
{
if (tree == NULL)
return (1);

if (tree->n < min || tree->n > max)
return (0);

return (bst_helper(tree->left, min, tree->n - 1) &&
bst_helper(tree->right, tree->n + 1, max));
}
