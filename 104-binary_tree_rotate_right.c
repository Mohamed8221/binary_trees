#include "binary_trees.h"

/**
* binary_tree_rotate_right - performs a right-rotation on a binary tree
* @tree: pointer to the root node of the tree to rotate
*
* Return: pointer to the new root node of the tree once rotated
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
binary_tree_t *new_root = NULL;

if (tree == NULL || tree->left == NULL)
return (NULL);

new_root = tree->left;
tree->left = new_root->right;
if (new_root->right != NULL)
new_root->right->parent = tree;
new_root->parent = tree->parent;
if (tree->parent == NULL)
tree = new_root;
else if (tree == tree->parent->right)
tree->parent->right = new_root;
else
tree->parent->left = new_root;
new_root->right = tree;
tree->parent = new_root;

return (new_root);
}
