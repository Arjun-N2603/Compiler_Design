%{
	#include "sym_tab.h"
	#include "sym_tab.c" 
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h> // For isdigit, etc.

	#define YYSTYPE char*

	void yyerror(char* s);
	int yylex();
	extern int yylineno;

    table* sym_table; // Global symbol table
    int current_scope = 0; // Global scope is 1
    int current_type; // To store the current type being declared

    int get_type_code(char* type_str); // Function to get type code from string
    int get_size_from_type(int type_code); // Function to get size from type code

    // To track types during expression evaluation
    int E_type, T_type, F_type;

    int infer_num_type(char* num_str); // Function to infer type of number literal

%}

%token T_INT T_CHAR T_DOUBLE T_WHILE  T_INC T_DEC   T_OROR T_ANDAND T_EQCOMP T_NOTEQUAL T_GREATEREQ T_LESSEREQ T_LEFTSHIFT T_RIGHTSHIFT T_PRINTLN T_STRING  T_FLOAT T_BOOLEAN T_IF T_ELSE T_STRLITERAL T_DO T_INCLUDE T_HEADER T_MAIN T_ID T_NUM

%start START

%%
START : PROG { printf("Valid syntax\n"); display_symbol_table(sym_table); YYACCEPT; }
        ;

PROG :  MAIN PROG
	| DECLR ';' PROG
	| ASSGN ';' PROG
	| IF_STMT PROG
	| /*epsilon*/
	;


DECLR : TYPE { current_type = get_type_code($1); free($1); } LISTVAR
	;


LISTVAR : LISTVAR ',' VAR
	  | VAR
	  ;

VAR: T_ID '=' EXPR 	{
                if (check_symbol_table(sym_table, $1)) {
                    fprintf(stderr, "Error: Redeclaration of variable '%s' at line %d\n", $1, yylineno);
                } else {
                    int size = get_size_from_type(current_type);
                    symbol* sym = init_symbol($1, size, current_type, yylineno, current_scope);
                    insert_into_table(sym_table, sym);
                    insert_value_to_name(sym_table, $1, $3); // Assign initial value from EXPR
                }
                free($1);
                free($3); // Free EXPR's value
			}
     | T_ID 		{
                if (check_symbol_table(sym_table, $1)) {
                    fprintf(stderr, "Error: Redeclaration of variable '%s' at line %d\n", $1, yylineno);
                } else {
                    int size = get_size_from_type(current_type);
                    symbol* sym = init_symbol($1, size, current_type, yylineno, current_scope);
                    insert_into_table(sym_table, sym);
                }
                free($1);
			}

//assign type here to be returned to the declaration grammar
TYPE : T_INT { $$ = strdup("int"); }
       | T_FLOAT { $$ = strdup("float"); }
       | T_DOUBLE { $$ = strdup("double"); }
       | T_CHAR { $$ = strdup("char"); }
       ;

/* Grammar for assignment */
ASSGN : T_ID '=' EXPR 	{
                if (!check_symbol_table(sym_table, $1)) {
                    fprintf(stderr, "Error: Undeclared variable '%s' at line %d\n", $1, yylineno);
                } else {
                    insert_value_to_name(sym_table, $1, $3);
                }
                free($1);
                free($3); // Free EXPR's value
			}
	;

EXPR : EXPR REL_OP E   { /* For relational operators - to be implemented later if needed */ }
       | E             { $$ = strdup($1); free($1); E_type = E_type; } // Pass value and type of E up
       ;

E : E '+' T   {
                char* val_e = $1;
                char* val_t = $3;
                double num_e, num_t, result_double;
                char result_str[50];
                int result_type;

                if ((E_type == INT_TYPE || E_type == FLOAT_TYPE || E_type == DOUBLE_TYPE) &&
                    (T_type == INT_TYPE || T_type == FLOAT_TYPE || T_type == DOUBLE_TYPE)) {

                    num_e = atof(val_e);
                    num_t = atof(val_t);
                    result_double = num_e + num_t;

                    result_type = (E_type == DOUBLE_TYPE || T_type == DOUBLE_TYPE) ? DOUBLE_TYPE :
                                  (E_type == FLOAT_TYPE || T_type == FLOAT_TYPE) ? FLOAT_TYPE : INT_TYPE;
                    E_type = result_type; // Set E's type

                    if (result_type == INT_TYPE) {
                        sprintf(result_str, "%d", (int)result_double);
                    } else if (result_type == FLOAT_TYPE) {
                        sprintf(result_str, "%.6f", (float)result_double);
                    } else { // DOUBLE_TYPE
                        sprintf(result_str, "%lf", result_double);
                    }
                    $$ = strdup(result_str);
                } else {
                    yyerror("Type mismatch in addition");
                    $$ = strdup("0");
                    E_type = INT_TYPE; // Default error type
                }
                free(val_e);
                free(val_t);
            }
    | E '-' T   {
                char* val_e = $1;
                char* val_t = $3;
                double num_e, num_t, result_double;
                char result_str[50];
                int result_type;

                if ((E_type == INT_TYPE || E_type == FLOAT_TYPE || E_type == DOUBLE_TYPE) &&
                    (T_type == INT_TYPE || T_type == FLOAT_TYPE || T_type == DOUBLE_TYPE)) {

                    num_e = atof(val_e);
                    num_t = atof(val_t);
                    result_double = num_e - num_t;
                    result_type = (E_type == DOUBLE_TYPE || T_type == DOUBLE_TYPE) ? DOUBLE_TYPE :
                                  (E_type == FLOAT_TYPE || T_type == FLOAT_TYPE) ? FLOAT_TYPE : INT_TYPE;
                    E_type = result_type;

                    if (result_type == INT_TYPE) {
                        sprintf(result_str, "%d", (int)result_double);
                    } else if (result_type == FLOAT_TYPE) {
                        sprintf(result_str, "%.6f", (float)result_double);
                    } else { // DOUBLE_TYPE
                        sprintf(result_str, "%lf", result_double);
                    }
                    $$ = strdup(result_str);
                } else {
                    yyerror("Type mismatch in subtraction");
                    $$ = strdup("0");
                    E_type = INT_TYPE;
                }
                free(val_e);
                free(val_t);
            }
    | T         { $$ = strdup($1); free($1); E_type = T_type; } // Pass value and type of T up
    ;


T : T '*' F   {
                char* val_t = $1;
                char* val_f = $3;
                double num_t, num_f, result_double;
                char result_str[50];
                int result_type;

                if ((T_type == INT_TYPE || T_type == FLOAT_TYPE || T_type == DOUBLE_TYPE) &&
                    (F_type == INT_TYPE || F_type == FLOAT_TYPE || F_type == DOUBLE_TYPE)) {

                    num_t = atof(val_t);
                    num_f = atof(val_f);
                    result_double = num_t * num_f;
                    result_type = (T_type == DOUBLE_TYPE || F_type == DOUBLE_TYPE) ? DOUBLE_TYPE :
                                  (T_type == FLOAT_TYPE || F_type == FLOAT_TYPE) ? FLOAT_TYPE : INT_TYPE;
                    T_type = result_type;

                    if (result_type == INT_TYPE) {
                        sprintf(result_str, "%d", (int)result_double);
                    } else if (result_type == FLOAT_TYPE) {
                        sprintf(result_str, "%.6f", (float)result_double);
                    } else { // DOUBLE_TYPE
                        sprintf(result_str, "%lf", result_double);
                    }
                    $$ = strdup(result_str);
                } else {
                    yyerror("Type mismatch in multiplication");
                    $$ = strdup("0");
                    T_type = INT_TYPE;
                }
                free(val_t);
                free(val_f);
            }
    | T '/' F   {
                char* val_t = $1;
                char* val_f = $3;
                double num_t, num_f, result_double;
                char result_str[50];
                int result_type;

                if ((T_type == INT_TYPE || T_type == FLOAT_TYPE || T_type == DOUBLE_TYPE) &&
                    (F_type == INT_TYPE || F_type == FLOAT_TYPE || F_type == DOUBLE_TYPE)) {
                    num_t = atof(val_t);
                    num_f = atof(val_f);
                    if (num_f == 0.0) {
                        yyerror("Division by zero");
                        $$ = strdup("0");
                        T_type = INT_TYPE;
                    } else {
                        result_double = num_t / num_f;
                        result_type = (T_type == DOUBLE_TYPE || F_type == DOUBLE_TYPE) ? DOUBLE_TYPE :
                                      (T_type == FLOAT_TYPE || F_type == FLOAT_TYPE) ? FLOAT_TYPE : INT_TYPE;
                        T_type = result_type;
                        if (result_type == INT_TYPE) {
                            sprintf(result_str, "%d", (int)result_double);
                        } else if (result_type == FLOAT_TYPE) {
                            sprintf(result_str, "%.6f", (float)result_double);
                        } else { // DOUBLE_TYPE
                            sprintf(result_str, "%lf", result_double);
                        }
                        $$ = strdup(result_str);
                    }
                } else {
                    yyerror("Type mismatch in division");
                    $$ = strdup("0");
                    T_type = INT_TYPE;
                }
                free(val_t);
                free(val_f);
            }
    | F         { $$ = strdup($1); free($1); T_type = F_type; } // Pass value and type of F up
    ;

F : '(' EXPR ')' { $$ = strdup($2); free($2); F_type = E_type; } // Type of F is type of EXPR
    | T_ID         {
                    symbol* sym = get_symbol_entry(sym_table, $1);
                    if (sym == NULL) {
                        yyerror("Undeclared variable in expression");
                        $$ = strdup("0");
                        F_type = INT_TYPE; //Default error type
                    } else if (sym->val == NULL) {
                        yyerror("Variable not initialized in expression");
                        $$ = strdup("0");
                        F_type = sym->type; //Or default to INT_TYPE?
                    }
                    else {
                        $$ = strdup(sym->val);
                        F_type = sym->type;
                    }
                    free($1);
                  }
    | T_NUM        {
                    $$ = strdup($1);
                    F_type = infer_num_type($1); // Infer type of number literal
                    free($1);
                  }
    | T_STRLITERAL { $$ = strdup($1); free($1); F_type = CHAR_TYPE; /* or STRING_TYPE if you define one */ } // Treat string literal as char type for now
    ;

REL_OP :   T_LESSEREQ
	   | T_GREATEREQ
	   | '<'
	   | '>'
	   | T_EQCOMP
	   | T_NOTEQUAL
	   ;

// Grammar for IF statement
IF_STMT : T_IF '(' EXPR ')' STMT     {
            printf("IF statement parsed.\n");
            free($3); // Free EXPR's value
         }
        | T_IF '(' EXPR ')' STMT T_ELSE STMT {
            printf("IF-ELSE statement parsed.\n");
            free($3); // Free EXPR's value
        }
        ;


/* Grammar for main function */
MAIN : TYPE T_MAIN '(' EMPTY_LISTVAR ')' '{'
         { current_scope++; } // Increment scope when entering MAIN's body
         STMT
         { current_scope--; } // Decrement scope when exiting MAIN's body
      '}'
     ;

EMPTY_LISTVAR : LISTVAR
		|
		;

STMT : STMT_NO_BLOCK STMT
       | BLOCK STMT
       | IF_STMT STMT
       | /*epsilon*/
       ;


STMT_NO_BLOCK : DECLR ';'
       | ASSGN ';'
       ;

BLOCK : '{'
          { current_scope++; } // Increment scope when entering BLOCK
          STMT
          { current_scope--; } // Decrement scope when exiting BLOCK
       '}'
       ;

COND : EXPR
       | ASSGN
       ;


%%


/* error handling function */
void yyerror(char* s)
{
	printf("Error :%s at line %d\n",s,yylineno);
}

int get_type_code(char* type_str) {
    if (strcmp(type_str, "int") == 0) return INT_TYPE;
    if (strcmp(type_str, "char") == 0) return CHAR_TYPE;
    if (strcmp(type_str, "float") == 0) return FLOAT_TYPE;
    if (strcmp(type_str, "double") == 0) return DOUBLE_TYPE;
    return 0; // Unknown type
}

int get_size_from_type(int type_code) {
    switch (type_code) {
        case CHAR_TYPE: return 1;
        case INT_TYPE: return 2;
        case FLOAT_TYPE: return 4;
        case DOUBLE_TYPE: return 8;
        default: return 0; // Unknown size
    }
}

// Infer type of number literal (T_NUM)
int infer_num_type(char* num_str) {
    int is_float = 0;
    for (int i = 0; num_str[i] != '\0'; i++) {
        if (num_str[i] == '.' || tolower(num_str[i]) == 'e') {
            is_float = 1;
            break;
        }
    }
    if (is_float) {
        return FLOAT_TYPE; // Or DOUBLE_TYPE if you want to default to double for floating point literals
    } else {
        return INT_TYPE;
    }
}


int main(int argc, char *argv[]) {
    // If an input file is provided as a command line argument, open it.
    if (argc > 1) {
        FILE *fp = freopen(argv[1], "r", stdin);
        if (!fp) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
    }
    sym_table = init_table();
    yyparse();
    return 0;
}