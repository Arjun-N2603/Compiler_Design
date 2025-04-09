#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quad_generation.h"

// Structure to store quadruples
typedef struct quadruple {
    char op[10];
    char arg1[20];
    char arg2[20];
    char result[20];
    struct quadruple* next;
} quadruple;

// Global variables
int label_no = 1;
quadruple* quad_list = NULL;
quadruple* quad_tail = NULL;

// Function to add a new quadruple to the list
void add_quad(char* op, char* arg1, char* arg2, char* result) {
    quadruple* new_quad = (quadruple*)malloc(sizeof(quadruple));
    strcpy(new_quad->op, op);
    strcpy(new_quad->arg1, arg1 ? arg1 : "");
    strcpy(new_quad->arg2, arg2 ? arg2 : "");
    strcpy(new_quad->result, result ? result : "");
    new_quad->next = NULL;
    
    if (quad_list == NULL) {
        quad_list = new_quad;
        quad_tail = new_quad;
    } else {
        quad_tail->next = new_quad;
        quad_tail = new_quad;
    }
}

void quad_code_gen(char* a, char* b, char* op, char* c) {
    add_quad(op, b, c, a);
}

char* new_temp() {
    char* temp = (char*)malloc(sizeof(char)*10);
    sprintf(temp, "t%d", temp_no);
    ++temp_no;
    return temp;
}

char* new_label() {
    char* label = (char*)malloc(sizeof(char)*10);
    sprintf(label, "L%d", label_no);
    ++label_no;
    return label;
}

// Function to generate three-address code
void emit_3ac(char* op, char* arg1, char* arg2, char* result) {
    if (strcmp(op, "Label") == 0) {
        printf("%s :\t ", result);
    } else if (strcmp(op, "goto") == 0) {
        printf("%s \t\t\t %s\n", op, result);
    } else if (strcmp(op, "If") == 0) {
        printf("if %s goto %s\n", arg1, result);
    } else if (strcmp(op, "=") == 0) {
        printf("%s = %s\n", result, arg1);
    } else {
        printf("%s = %s %s %s\n", result, arg1, op, arg2);
    }
}

// Check if a label is referenced by any quad
int is_label_referenced(char* label) {
    quadruple* q = quad_list;
    while (q != NULL) {
        if ((strcmp(q->op, "goto") == 0 || strcmp(q->op, "If") == 0) && 
            strcmp(q->result, label) == 0) {
            return 1;
        }
        q = q->next;
    }
    return 0;
}

// Function to print the 3AC from quadruple list
void print_three_address_code() {
    printf("Three address code:\n");
    quadruple* q = quad_list;
    while (q != NULL) {
        if (strcmp(q->op, "Label") == 0) {
            // Only print the label if it's referenced somewhere
            // or if it's not the last quad
            if (is_label_referenced(q->result) || q->next != NULL) {
                printf("%s :\t ", q->result);
            }
        } else if (strcmp(q->op, "goto") == 0) {
            printf("goto %s\n", q->result);
        } else if (strcmp(q->op, "If") == 0) {
            printf("if %s goto %s\n", q->arg1, q->result);
        } else if (strcmp(q->op, "=") == 0) {
            printf("%s = %s\n", q->result, q->arg1);
        } else {
            printf("%s = %s %s %s\n", q->result, q->arg1, q->op, q->arg2);
        }
        q = q->next;
    }
    printf("\n");
}

// Function to print the quadruple table
void print_quad_table() {
    printf("op\targ1\targ2\tresult\n");
    quadruple* q = quad_list;
    while (q != NULL) {
        printf("%s\t%s\t%s\t%s\n", q->op, q->arg1, q->arg2, q->result);
        q = q->next;
    }
}