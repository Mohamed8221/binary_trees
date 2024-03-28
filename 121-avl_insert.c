#include "binary_trees.h"

/**
* insert_node - Inserts a node into an AVL tree
* @tree: Double pointer to the root node of the AVL tree
* @value: Value to store in the node to be inserted
*
* Return: Pointer to the created node, or NULL on failure
*/
avl_t *insert_node(avl_t **tree, int value)
{
avl_t *new_node = NULL;

if (value < (*tree)->n)
{
new_node = avl_insert(&((*tree)->left), value);
if (new_node == NULL)
return (NULL);
(*tree)->left->parent = *tree;
}
else if (value > (*tree)->n)
{
new_node = avl_insert(&((*tree)->right), value);
if (new_node == NULL)
return (NULL);
(*tree)->right->parent = *tree;
}
else
return (NULL);

return (new_node);
}

/**
* avl_insert - Inserts a value in an AVL Tree
* @tree: Double pointer to the root node of the AVL tree
* @value: Value to store in the node to be inserted
*
* Return: Pointer to the created node, or NULL on failure
*/
avl_t *avl_insert(avl_t **tree, int value)
{
int balance;
avl_t *new_node = NULL;

if (tree == NULL)
return (NULL);

if (*tree == NULL)
{
*tree = binary_tree_node(NULL, value);
return (*tree);
}

new_node = insert_node(tree, value);

balance = binary_tree_balance(*tree);

if (balance > 1 && value < (*tree)->left->n)
return (binary_tree_rotate_right(*tree));

if (balance < -1 && value > (*tree)->right->n)
return (binary_tree_rotate_left(*tree));

if (balance > 1 && value > (*tree)->left->n)
{
(*tree)->left = binary_tree_rotate_left((*tree)->left);
return (binary_tree_rotate_right(*tree));
}

if (balance < -1 && value < (*tree)->right->n)
{
(*tree)->right = binary_tree_rotate_right((*tree)->right);
return (binary_tree_rotate_left(*tree));
}

return (*tree);
}
