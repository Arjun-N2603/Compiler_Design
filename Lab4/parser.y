%{
    #include "abstract_syntax_tree.h"  // Include the header file
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    void yyerror(char* s);
    int yylex();
    extern int yylineno;
    extern FILE* yyin; // Declare the input file stream for the lexer
%}

%union {
    char* text;
    expression_node* exp_node;
}

%token <text> T_ID T_NUM

%type <exp_node> E T F ASSGN START

%start START

%%

START : ASSGN   { display_exp_tree($1); printf("Valid syntax\n"); YYACCEPT; }

ASSGN : T_ID '=' E  { $$ = init_exp_node("=", init_exp_node($1, NULL, NULL), $3); }
      ;

E : E '+' T     { $$ = init_exp_node("+", $1, $3); }
  | E '-' T     { $$ = init_exp_node("-", $1, $3); }
  | T           { $$ = $1; }
  ;

T : T '*' F     { $$ = init_exp_node("*", $1, $3); }
  | T '/' F     { $$ = init_exp_node("/", $1, $3); }
  | F           { $$ = $1; }
  ;

F : '(' E ')'   { $$ = $2; }
  | T_ID        { $$ = init_exp_node($1, NULL, NULL); }
  | T_NUM       { $$ = init_exp_node($1, NULL, NULL); }
  ;

%%

void yyerror(char* s) {
    printf("Error :%s at %d \n", s, yylineno);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    yyin = file; // Redirect lexer input to the file
    yyparse();   // Start parsing
    fclose(file); // Close the file after parsing
    return 0;
}