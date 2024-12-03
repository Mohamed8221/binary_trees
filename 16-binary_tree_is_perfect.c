#include "binary_trees.h"

/**
* binary_tree_is_perfect - checks if a binary tree is perfect
* @tree: pointer to the root node of the tree to check
*
* Return: 1 if the binary tree is perfect, otherwise 0.
* If tree is NULL, return 0.
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
int depth_left, depth_right;

if (tree == NULL)
return (0);

// Calculate the depth of the left and right subtrees
depth_left = binary_tree_depth(tree->left);
depth_right = binary_tree_depth(tree->right);

// Check if both subtrees have the same depth
if (depth_left != depth_right)
return (0);

// Check if both left and right children are present
if (tree->left == NULL && tree->right == NULL)
return (1);

if (tree->left != NULL && tree->right != NULL)
return (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right));

return (0);
}

/**
* binary_tree_depth - measures the depth of a node in a binary tree
* @tree: pointer to the node to measure the depth
*
* Return: depth of a node in a binary tree. If tree is NULL, return 0.
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
size_t depth = 0;

if (tree == NULL)
return (0);

while (tree->parent)
{
depth++;
tree = tree->parent;
}

return (depth);
}
