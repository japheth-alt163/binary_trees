#include "binary_trees.h"

/**
 * binary_tree_size - Measure the size of a binary tree
 * @tree: A pointer to the root node of the tree to measure
 *
 * Return: The size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * is_complete - Check if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 * @index: The index of the current node
 * @node_count: The total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t node_count)
{
    if (tree == NULL)
        return (1);

    if (index >= node_count)
        return (0);

    return (is_complete(tree->left, 2 * index + 1, node_count) &&
            is_complete(tree->right, 2 * index + 2, node_count));
}

/**
 * binary_tree_is_heap - Check if a binary tree is a valid Max Binary Heap
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    if (!is_complete(tree, 0, binary_tree_size(tree)))
        return (0);

    if (tree->left && tree->left->n > tree->n)
        return (0);

    if (tree->right && tree->right->n > tree->n)
        return (0);

    return (binary_tree_is_heap(tree->left) && binary_tree_is_heap(tree->right));
}
