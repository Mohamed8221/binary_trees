#include "binary_trees.h"

/**
* minValueNode - gets the node with the smallest value in a BST
* @node: a pointer to the root of the BST
*
* Return: a pointer to the node with the smallest value in the BST
*/
bst_t *minValueNode(bst_t *node)
{
bst_t *current = node;

/* loop down to find the leftmost leaf */
while (current && current->left != NULL)
current = current->left;

return (current);
}

/**
* bst_remove - removes a node from a Binary Search Tree
* @root: a pointer to the root node of the tree where you will remove a node
* @value: the value to remove in the tree
*
* Return: a pointer to the new root node of the tree after removing
* the desired value
*/
bst_t *bst_remove(bst_t *root, int value)
{
if (root == NULL)
return (root);

if (value < root->n)
root->left = bst_remove(root->left, value);

else if (value > root->n)
root->right = bst_remove(root->right, value);

else
{
if (root->left == NULL)
{
bst_t *temp = root->right;
free(root);
return (temp);
}
else if (root->right == NULL)
{
bst_t *temp = root->left;
free(root);
return (temp);
}

bst_t *temp = minValueNode(root->right);

root->n = temp->n;

root->right = bst_remove(root->right, temp->n);
}
return (root);
}
