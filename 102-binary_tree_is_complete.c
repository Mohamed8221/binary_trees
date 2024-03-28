#include "binary_trees.h"
#include <stdlib.h>

/**
* binary_tree_is_complete - checks if a binary tree is complete
* @tree: pointer to the root node of the tree to check
*
* Return: 1 if tree is a complete binary tree, and 0 otherwise
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

if (tree->left == NULL && tree->right == NULL)
return (1);

if (tree->left != NULL && tree->right != NULL)
return (binary_tree_is_complete(tree->left) &&
binary_tree_is_complete(tree->right));

return (0);
}
