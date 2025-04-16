%{
	#include "sym_tab.h"
	#include "sym_tab.c" // Including .c for simplicity in this example. In real projects, compile and link.
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#define YYSTYPE char*

	void yyerror(char* s);
	int yylex();
	extern int yylineno;

    table* sym_table; // Global symbol table
    int current_scope = 1; // Default scope is 1

    int current_type; // To store the current type being declared
    int get_type_code(char* type_str); // Function to get type code from string
    int get_size_from_type(int type_code); // Function to get size from type code

%}

%token T_INT T_CHAR T_DOUBLE T_WHILE  T_INC T_DEC   T_OROR T_ANDAND T_EQCOMP T_NOTEQUAL T_GREATEREQ T_LESSEREQ T_LEFTSHIFT T_RIGHTSHIFT T_PRINTLN T_STRING  T_FLOAT T_BOOLEAN T_IF T_ELSE T_STRLITERAL T_DO T_INCLUDE T_HEADER T_MAIN T_ID T_NUM

%start START

%%
START : PROG { printf("Valid syntax\n"); display_symbol_table(sym_table); YYACCEPT; }
        ;

PROG :  MAIN PROG
	| DECLR ';' PROG
	| ASSGN ';' PROG
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
                }
                free($1);
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
TYPE : T_INT { $$ = strdup($1); }
       | T_FLOAT { $$ = strdup($1); }
       | T_DOUBLE { $$ = strdup($1); }
       | T_CHAR { $$ = strdup($1); }
       ;

/* Grammar for assignment */
ASSGN : T_ID '=' EXPR 	{
                if (!check_symbol_table(sym_table, $1)) {
                    fprintf(stderr, "Error: Undeclared variable '%s' at line %d\n", $1, yylineno);
                } else {
                    insert_value_to_name(sym_table, $1, $3);
                }
                free($1);
			}
	;

EXPR : EXPR REL_OP E
       | E
       ;

E : E '+' T
    | E '-' T
    | T
    ;


T : T '*' F
    | T '/' F
    | F
    ;

F : '(' EXPR ')'
    | T_ID
    | T_NUM
    | T_STRLITERAL
    ;

REL_OP :   T_LESSEREQ
	   | T_GREATEREQ
	   | '<'
	   | '>'
	   | T_EQCOMP
	   | T_NOTEQUAL
	   ;


/* Grammar for main function */
MAIN : TYPE T_MAIN '(' EMPTY_LISTVAR ')' '{' STMT '}';

EMPTY_LISTVAR : LISTVAR
		|
		;

STMT : STMT_NO_BLOCK STMT
       | BLOCK STMT
       | /*epsilon*/
       ;


STMT_NO_BLOCK : DECLR ';'
       | ASSGN ';'
       ;

BLOCK : '{' STMT '}';

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