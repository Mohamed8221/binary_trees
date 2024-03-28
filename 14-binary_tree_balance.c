#include "binary_trees.h"

/**
 * calc_balance - calculates the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to calculate the balance factor
 *
 * Return: balance factor of a binary tree. If tree is NULL, return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    int left_height = 0;
    int right_height = 0;

    if (tree == NULL)
        return (0);

    left_height = tree->left ? measure_height(tree->left) + 1 : 0;
    right_height = tree->right ? measure_height(tree->right) + 1 : 0;

    return (left_height - right_height);
}

/**
 * measure_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of a binary tree. If tree is NULL, return 0.
 */
size_t measure_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    else
    {
        /* compute the height of each subtree */
        size_t left_subtree_height = measure_height(tree->left);
        size_t right_subtree_height = measure_height(tree->right);

        /* use the larger one */
        if (left_subtree_height > right_subtree_height)
            return(left_subtree_height + 1);
        else return(right_subtree_height + 1);
    }
}
