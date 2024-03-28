#include "binary_trees.h"

/**
* binary_tree_balance - measures the balance factor of a binary tree
* @tree: pointer to the root node of the tree to measure the balance factor
*
* Return: balance factor of a binary tree. If tree is NULL, return 0.
*/
int binary_tree_balance(const binary_tree_t *tree)
{
int height_left = 0;
int height_right = 0;

if (tree == NULL)
return (0);

height_left = tree->left ? binary_tree_height(tree->left) : 0;
height_right = tree->right ? binary_tree_height(tree->right) : 0;

return (height_left - height_right);
}

/**
* binary_tree_height - measures the height of a binary tree
* @tree: pointer to the root node of the tree to measure the height
*
* Return: height of a binary tree. If tree is NULL, return 0.
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
else
{
size_t left_height = binary_tree_height(tree->left);
size_t right_height = binary_tree_height(tree->right);

if (left_height > right_height)
return (left_height + 1);
else
return (right_height + 1);
}
}
