#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sym_tab.h"

table* init_table()
{
    table* t = (table*)malloc(sizeof(table));
    if (t == NULL) {
        fprintf(stderr, "Memory allocation failed for symbol table.\n");
        exit(EXIT_FAILURE);
    }
    t->head = NULL;
    return t;
}

symbol* init_symbol(char* name, int size, int type, int lineno, int scope)
{
    symbol* s = (symbol*)malloc(sizeof(symbol));
    if (s == NULL) {
        fprintf(stderr, "Memory allocation failed for symbol entry.\n");
        exit(EXIT_FAILURE);
    }
    s->name = strdup(name); // Allocate memory and copy name
    s->size = size;
    s->type = type;
    s->val = NULL; // Value will be updated later
    s->line = lineno;
    s->scope = scope;
    s->next = NULL;
    return s;
}

void insert_into_table(table* sym_table, symbol* sym_entry)
{
    if (sym_table == NULL || sym_entry == NULL) {
        fprintf(stderr, "Invalid arguments to insert_into_table.\n");
        return;
    }

    if (sym_table->head == NULL) {
        sym_table->head = sym_entry;
    } else {
        symbol* current = sym_table->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = sym_entry;
    }
}

int check_symbol_table(table* sym_table, char* name)
{
    if (sym_table == NULL || name == NULL) {
        return 0; // Not found or invalid table
    }

    symbol* current = sym_table->head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return 1; // Found
        }
        current = current->next;
    }
    return 0; // Not found
}

void insert_value_to_name(table* sym_table, char* name, char* value)
{
    if (sym_table == NULL || name == NULL) {
        return;
    }
    if (value == NULL) return; // if value is default value return back

    symbol* current = sym_table->head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (current->val != NULL) free(current->val); // Free old value if exists
            current->val = strdup(value);
            return;
        }
        current = current->next;
    }
     printf("Warning: Variable '%s' not found in symbol table to update value.\n", name);
}


void display_symbol_table(table* sym_table)
{
    if (sym_table == NULL) {
        printf("Symbol table is NULL.\n");
        return;
    }

    printf("Symbol Table:\n");
    printf("--------------------------------------------------------------------\n");
    printf("Name\tSize\tType\tLine No\tScope\tValue\n");
    printf("--------------------------------------------------------------------\n");

    symbol* current = sym_table->head;
    while (current != NULL) {
        char* type_str;
        switch (current->type) {
            case CHAR_TYPE: type_str = "char"; break;
            case INT_TYPE: type_str = "int"; break;
            case FLOAT_TYPE: type_str = "float"; break;
            case DOUBLE_TYPE: type_str = "double"; break;
            default: type_str = "unknown"; break;
        }
        printf("%s\t%d\t%s\t%d\t%d\t%s\n", current->name, current->size, type_str, current->line, current->scope, current->val != NULL ? current->val : "~");
        current = current->next;
    }
    printf("--------------------------------------------------------------------\n");
}