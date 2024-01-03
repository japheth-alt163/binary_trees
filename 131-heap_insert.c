#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_height - Measure the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure
 *
 * Return: The height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect
 * @tree: A pointer to the root node of the tree to check
 * @depth: The depth of the tree
 * @level: The level to check for perfection
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree, size_t depth, size_t level)
{
    if (tree == NULL)
        return (1);

    if (tree->left == NULL && tree->right == NULL)
        return (depth == level + 1);

    if (tree->left == NULL || tree->right == NULL)
        return (0);

    return (binary_tree_is_perfect(tree->left, depth, level + 1) &&
            binary_tree_is_perfect(tree->right, depth, level + 1));
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: A double pointer to the root node of the Heap
 * @value: The value to insert
 *
 * Return: A pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;
    size_t depth, level = 0;

    if (*root == NULL)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    depth = binary_tree_height(*root);

    for (parent = *root; parent; parent = parent->left)
    {
        if (!parent->left)
        {
            new_node = binary_tree_node(parent, value);
            parent->left = new_node;
        }
        else if (!parent->right)
        {
            new_node = binary_tree_node(parent, value);
            parent->right = new_node;
        }

        if (binary_tree_is_perfect(*root, depth, level + 1))
            return (new_node);
    }

    return (NULL);
}
