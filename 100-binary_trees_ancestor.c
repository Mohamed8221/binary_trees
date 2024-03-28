#include "binary_trees.h"

/**
* binary_trees_ancestor - finds the lowest common ancestor of two nodes
* @first: pointer to the first node
* @second: pointer to the second node
*
* Return: pointer to the lowest common ancestor node of the two given nodes.
* If no common ancestor was found, return NULL.
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
binary_tree_t *mover = (binary_tree_t *)first;

if (first == NULL || second == NULL)
return (NULL);

while (second)
{
while (mover)
{
if (second == mover)
return ((binary_tree_t *)second);
mover = mover->parent;
}
second = second->parent;
mover = (binary_tree_t *)first;
}

return (NULL);
}
