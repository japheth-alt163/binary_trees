#include "binary_trees.h"

avl_t *avl_insert_recursive(avl_t **node, int value);

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to insert in the AVL tree
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (!tree)
        return NULL;

    return avl_insert_recursive(tree, value);
}

/**
 * avl_insert_recursive - Recursive helper function to insert a value in AVL Tree
 * @node: Pointer to the current node being considered
 * @value: Value to insert in the AVL tree
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert_recursive(avl_t **node, int value)
{
    int balance;

    if (!(*node))
    {
        *node = binary_tree_node(NULL, value);
        if (!(*node))
            return NULL;
        return *node;
    }

    if (value < (*node)->n)
    {
        (*node)->left = avl_insert_recursive(&((*node)->left), value);
    }
    else if (value > (*node)->n)
    {
        (*node)->right = avl_insert_recursive(&((*node)->right), value);
    }
    else
    {
        return NULL; /* Duplicate values are not allowed in AVL Tree */
    }

    balance = binary_tree_balance(*node);

    /* Left Heavy */
    if (balance > 1)
    {
        if (value < (*node)->left->n)
        {
            return binary_tree_rotate_right(node);
        }
        else
        {
            (*node)->left = binary_tree_rotate_left(&((*node)->left));
            return binary_tree_rotate_right(node);
        }
    }

    /* Right Heavy */
    if (balance < -1)
    {
        if (value > (*node)->right->n)
        {
            return binary_tree_rotate_left(node);
        }
        else
        {
            (*node)->right = binary_tree_rotate_right(&((*node)->right));
            return binary_tree_rotate_left(node);
        }
    }

    return *node;
}
