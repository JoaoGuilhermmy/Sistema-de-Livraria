#include "bst.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

CategoryNode *new_node(int id, char category_name[], char books_file[])
{
    CategoryNode *n = (CategoryNode *)malloc(sizeof(CategoryNode));
    if (!n)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    n->id = id;
    strcpy(n->category_name, category_name);
    strcpy(n->books_file, books_file);
    n->left = n->right = NULL;
    return n;
}

CategoryNode *insert_category_node(CategoryNode *root, int id, char category_name[], char books_file[])
{
    if (root == NULL)
        return new_node(id, category_name, books_file);
    if (strcmp(category_name, root->category_name) < 0)
        root->left = insert_category_node(root->left, id, category_name, books_file);
    else if (strcmp(category_name, root->category_name) > 0)
        root->right = insert_category_node(root->right, id, category_name, books_file);
    return root;
}

CategoryNode *in_ordem_traversal(CategoryNode *root)
{
    if (root == NULL)
        return NULL;
    in_ordem_traversal(root->left);
    printf(" - %s\n", root->category_name);
    in_ordem_traversal(root->right);
    return root;
}