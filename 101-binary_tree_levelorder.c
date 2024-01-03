
#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    /* Create a queue for level order traversal */
    binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * binary_tree_size(tree));
    if (queue == NULL)
        return;

    int front = 0, rear = 0;
    binary_tree_t *current;

    /* Enqueue the root */
    queue[rear++] = (binary_tree_t *)tree;

    while (rear > front)
    {
        /* Dequeue a node and print it */
        current = queue[front++];
        func(current->n);

        /* Enqueue the left child if it exists */
        if (current->left)
            queue[rear++] = current->left;

        /* Enqueue the right child if it exists */
        if (current->right)
            queue[rear++] = current->right;
    }

    /* Free the queue */
    free(queue);
}
