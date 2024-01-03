#include "binary_trees.h"
#include <limits.h>

/**
 * is_avl - Checks if a binary tree is a valid AVL Tree recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @min: The minimum allowed value for the current node.
 * @max: The maximum allowed value for the current node.
 *
 * Return: 1 if the tree is a valid AVL Tree, 0 otherwise.
 */
int is_avl(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1);

    if (tree->n <= min || tree->n >= max)
        return (0);

    return (is_avl(tree->left, min, tree->n) &&
            is_avl(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (is_avl(tree, INT_MIN, INT_MAX));
}
