// abstract_syntax_tree.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abstract_syntax_tree.h"

expression_node* init_exp_node(char* val, expression_node* left, expression_node* right) {
    // Allocate memory for a new AST node
    expression_node* node = (expression_node*)malloc(sizeof(expression_node));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    // Copy the value string to ensure persistence
    node->value = strdup(val);
    if (node->value == NULL) {
        fprintf(stderr, "String duplication failed\n");
        free(node);
        exit(1);
    }
    node->left = left;   // Set the left child
    node->right = right; // Set the right child
    return node;
}

void display_exp_tree(expression_node* exp_node) {
    // Traverse the AST in preorder: root, left, right
    if (exp_node != NULL) {
        printf("%s \n", exp_node->value);    // Print the current node's value
        display_exp_tree(exp_node->left);  // Recurse on left child
        display_exp_tree(exp_node->right); // Recurse on right child
    }
}
