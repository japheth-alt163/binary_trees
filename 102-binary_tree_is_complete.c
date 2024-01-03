#include "binary_trees.h"

int is_complete(const binary_tree_t *tree, int index, int node_count);
int count_nodes(const binary_tree_t *tree);

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (is_complete(tree, 0, count_nodes(tree)));
}

/**
 * is_complete - Helper function to check if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * @index: Current index of the node
 * @node_count: Total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, int index, int node_count)
{
    if (tree == NULL)
        return (1);

    if (index >= node_count)
        return (0);

    return (is_complete(tree->left, 2 * index + 1, node_count) &&
            is_complete(tree->right, 2 * index + 2, node_count));
}

/**
 * count_nodes - Helper function to count the total number of nodes in a tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Total number of nodes in the tree
 */
int count_nodes(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}
