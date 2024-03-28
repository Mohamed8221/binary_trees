#include "binary_trees.h"

/**
* binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
* @tree: pointer to the root node of the tree to check
*
* Return: 1 if tree is a valid AVL Tree, and 0 otherwise
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
int height_diff;

if (tree == NULL)
return (0);

height_diff = binary_tree_balance(tree);

if (height_diff > 1 || height_diff < -1)
return (0);

if (tree->left && tree->n <= tree->left->n)
return (0);

if (tree->right && tree->n >= tree->right->n)
return (0);

if (!tree->left && !tree->right)
return (1);

if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
return (0);

return (1);
}

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
