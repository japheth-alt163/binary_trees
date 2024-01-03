#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree for removing a node
 * @value: Value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removing the value
 */
avl_t *avl_remove(avl_t *root, int value)
{
    if (!root)
        return NULL;

    root = avl_remove_recursive(root, value);
    return root;
}

/**
 * avl_remove_recursive - Recursive helper function to remove a node from AVL Tree
 * @node: Pointer to the current node being considered
 * @value: Value to remove in the AVL tree
 *
 * Return: Pointer to the new root node of the tree after removing the value
 */
avl_t *avl_remove_recursive(avl_t *node, int value)
{
    int balance;

    if (!node)
        return NULL;

    if (value < node->n)
    {
        node->left = avl_remove_recursive(node->left, value);
    }
    else if (value > node->n)
    {
        node->right = avl_remove_recursive(node->right, value);
    }
    else
    {
        /* Node with only one child or no child */
        if (!node->left || !node->right)
        {
            avl_t *temp = node->left ? node->left : node->right;

            /* No child case */
            if (!temp)
            {
                temp = node;
                node = NULL;
            }
            else   /* One child case */
                *node = *temp; /* Copy the contents of the non-empty child */
            
            free(temp);
        }
        else
        {
            /* Node with two children, get the in-order successor */
            avl_t *temp = find_min(node->right);

            /* Copy the in-order successor's data to this node */
            node->n = temp->n;

            /* Delete the in-order successor */
            node->right = avl_remove_recursive(node->right, temp->n);
        }
    }

    if (!node)
        return NULL; /* If the tree had only one node, it's deleted */

    balance = binary_tree_balance(node);

    /* Left Heavy */
    if (balance > 1)
    {
        if (binary_tree_balance(node->left) >= 0)
            return binary_tree_rotate_right(&node);
        else
        {
            node->left = binary_tree_rotate_left(&(node->left));
            return binary_tree_rotate_right(&node);
        }
    }

    /* Right Heavy */
    if (balance < -1)
    {
        if (binary_tree_balance(node->right) <= 0)
            return binary_tree_rotate_left(&node);
        else
        {
            node->right = binary_tree_rotate_right(&(node->right));
            return binary_tree_rotate_left(&node);
        }
    }

    return node;
}

/**
 * find_min - Finds the node with the minimum value in an AVL tree
 * @node: Pointer to the root node of the AVL tree
 *
 * Return: Pointer to the node with the minimum value
 */
avl_t *find_min(avl_t *node)
{
    while (node->left)
        node = node->left;
    
    return node;
}
