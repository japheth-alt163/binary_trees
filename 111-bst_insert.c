#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node;

    if (tree == NULL)
        return (NULL);

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    if (value < (*tree)->n)
    {
        if ((*tree)->left == NULL)
        {
            new_node = binary_tree_node(*tree, value);
            (*tree)->left = new_node;
            return (new_node);
        }
        return (bst_insert(&((*tree)->left), value));
    }
    else if (value > (*tree)->n)
    {
        if ((*tree)->right == NULL)
        {
            new_node = binary_tree_node(*tree, value);
            (*tree)->right = new_node;
            return (new_node);
        }
        return (bst_insert(&((*tree)->right), value));
    }
    return (NULL);  /* If the value is already present in the tree */
}
