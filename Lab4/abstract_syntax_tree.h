// abstract_syntax_tree.h
#ifndef ABSTRACT_SYNTAX_TREE_H
#define ABSTRACT_SYNTAX_TREE_H

typedef struct expression_node {
    char* value;                // String to store the node's value (e.g., operator, number, identifier)
    struct expression_node* left;  // Pointer to the left child
    struct expression_node* right; // Pointer to the right child
} expression_node;

expression_node* init_exp_node(char* val, expression_node* left, expression_node* right);
void display_exp_tree(expression_node* exp_node);

#endif