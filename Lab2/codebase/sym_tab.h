#ifndef SYM_TAB_H
#define SYM_TAB_H

#define CHAR_TYPE 1
#define INT_TYPE 2
#define FLOAT_TYPE 3
#define DOUBLE_TYPE 4

typedef struct symbol
{
    char* name;
    int size;
    int type;
    char* val;
    int line;
    int scope;
    struct symbol* next;
} symbol;

typedef struct table
{
    symbol* head;
} table;

extern table* sym_table; // Declare the global symbol table

table* init_table();

symbol* init_symbol(char* name, int size, int type, int lineno, int scope);

void insert_into_table(table* sym_table, symbol* sym_entry);

void insert_value_to_name(table* sym_table, char* name, char* value);

int check_symbol_table(table* sym_table, char* name);

void display_symbol_table(table* sym_table);

#endif // SYM_TAB_H