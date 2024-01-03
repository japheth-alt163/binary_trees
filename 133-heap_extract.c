#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node or 0 on failure
 */
int heap_extract(heap_t **root)
{
    int value;

    if (!root || !*root)
        return (0);

    value = (*root)->n;

    if ((*root)->left)
        heap_extract(&(*root)->left);
    if ((*root)->right)
        heap_extract(&(*root)->right);

    if (!(*root)->left && !(*root)->right)
    {
        if ((*root)->parent)
        {
            if ((*root)->parent->left == *root)
                (*root)->parent->left = NULL;
            else
                (*root)->parent->right = NULL;
        }
        free(*root);
        *root = NULL;
    }

    return (value);
}
