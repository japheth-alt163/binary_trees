#include "binary_trees.h"

/**
 * build_avl_tree - Recursively builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @start: Starting index of the subarray
 * @end: Ending index of the subarray
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *build_avl_tree(int *array, size_t start, size_t end)
{
    if (start > end)
        return NULL;

    size_t mid = (start + end) / 2;

    avl_t *root = binary_tree_node(NULL, array[mid]);
    if (!root)
        return NULL;

    root->left = build_avl_tree(array, start, mid - 1);
    root->right = build_avl_tree(array, mid + 1, end);

    return root;
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return NULL;

    return build_avl_tree(array, 0, size - 1);
}
