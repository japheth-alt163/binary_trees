#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* If a node has only one child, it cannot be a full tree */
    if ((tree->left == NULL && tree->right != NULL) ||
        (tree->left != NULL && tree->right == NULL))
        return (0);

    /* Recursively check both left and right subtrees */
    if (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right))
        return (1);

    return (0);
}
