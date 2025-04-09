#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abstract_syntax_tree.h"

expression_node* init_exp_node(char* val, expression_node* left, expression_node* right)
{
    expression_node* node = (expression_node*)malloc(sizeof(expression_node));
    node->val = strdup(val);
    node->left = left;
    node->right = right;
    return node;
}

statement_node* init_if_else_node(expression_node* condition, statement_node* if_body, statement_node* else_body, statement_node* next)
{
    statement_node* node = (statement_node*)malloc(sizeof(statement_node));
    node->type = strdup("if-else");
    node->condition = condition;
    node->if_body = if_body;
    node->else_body = else_body;
    node->next = next;
    return node;
}

statement_node* init_do_while_node(expression_node* condition, statement_node* body, statement_node* next)
{
    statement_node* node = (statement_node*)malloc(sizeof(statement_node));
    node->type = strdup("do-while");
    node->condition = condition;
    node->if_body = body;  // We'll use if_body to store the do-while body
    node->else_body = NULL;
    node->next = next;
    return node;
}

statement_node* init_assignment_node(expression_node* assign_exp, statement_node* next)
{
    statement_node* node = (statement_node*)malloc(sizeof(statement_node));
    node->type = strdup("assignment");
    node->condition = assign_exp;
    node->if_body = NULL;
    node->else_body = NULL;
    node->next = next;
    return node;
}

void display_exp_tree(expression_node* exp_node)
{
    if (exp_node == NULL)
        return;
    
    printf("%s\n", exp_node->val);
    display_exp_tree(exp_node->left);
    display_exp_tree(exp_node->right);
}

// Helper function to print indentation
void print_indent(int level) {
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
}

void display_statement_tree(statement_node* stmt_node, int indent_level)
{
    if (stmt_node == NULL)
        return;
    
    if (strcmp(stmt_node->type, "assignment") == 0) {
        print_indent(indent_level);
        printf("Assignment:\n");
        print_indent(indent_level + 1);
        printf("Expression:\n");
        display_exp_tree(stmt_node->condition);
    }
    else if (strcmp(stmt_node->type, "if-else") == 0) {
        print_indent(indent_level);
        if (stmt_node->else_body != NULL) {
            printf("If-Else Statement:\n");
        } else {
            printf("If Statement:\n");
        }
        print_indent(indent_level + 1);
        printf("Condition:\n");
        display_exp_tree(stmt_node->condition);
        print_indent(indent_level + 1);
        printf("If Body:\n");
        display_statement_tree(stmt_node->if_body, indent_level + 2);
        if (stmt_node->else_body) {
            print_indent(indent_level + 1);
            printf("Else Body:\n");
            display_statement_tree(stmt_node->else_body, indent_level + 2);
        }
    }
    else if (strcmp(stmt_node->type, "do-while") == 0) {
        print_indent(indent_level);
        printf("Do-While Statement:\n");
        print_indent(indent_level + 1);
        printf("Body:\n");
        display_statement_tree(stmt_node->if_body, indent_level + 2);
        print_indent(indent_level + 1);
        printf("Condition:\n");
        display_exp_tree(stmt_node->condition);
    }
    
    // Display the next statement
    display_statement_tree(stmt_node->next, indent_level);
}

// Helper function to print an expression node in flat format
void flat_display_exp_node(expression_node* exp_node) {
    if (exp_node == NULL)
        return;
    
    printf("%s", exp_node->val);
    
    if (exp_node->left != NULL) {
        printf(", ");
        flat_display_exp_node(exp_node->left);
    }
    
    if (exp_node->right != NULL) {
        printf(", ");
        flat_display_exp_node(exp_node->right);
    }
}

// Display statement tree in flat format with comma separation
void flat_display_statement_tree(statement_node* stmt_node, int is_first) {
    if (stmt_node == NULL)
        return;
    
    if (!is_first) {
        printf(", ");
    }
    
    if (strcmp(stmt_node->type, "assignment") == 0) {
        flat_display_exp_node(stmt_node->condition);
    }
    else if (strcmp(stmt_node->type, "if-else") == 0) {
        if (stmt_node->else_body == NULL) {
            printf("if");
            printf(", ");
            flat_display_exp_node(stmt_node->condition);
            
            if (stmt_node->if_body != NULL) {
                printf(", seq");
                flat_display_statement_tree(stmt_node->if_body, 0);
            }
        } else {
            printf("if-else");
            printf(", ");
            flat_display_exp_node(stmt_node->condition);
            
            if (stmt_node->if_body != NULL) {
                printf(", seq");
                flat_display_statement_tree(stmt_node->if_body, 0);
            }
            
            if (stmt_node->else_body != NULL) {
                printf(", seq");
                flat_display_statement_tree(stmt_node->else_body, 0);
            }
        }
    }
    else if (strcmp(stmt_node->type, "do-while") == 0) {
        printf("do-while");
        
        if (stmt_node->if_body != NULL) {
            printf(", seq");
            flat_display_statement_tree(stmt_node->if_body, 0);
        }
        
        printf(", ");
        flat_display_exp_node(stmt_node->condition);
    }
    
    // Display the next statement
    if (stmt_node->next != NULL) {
        flat_display_statement_tree(stmt_node->next, 0);
    }
}