%{
    #include "quad_generation.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define YYSTYPE char*

    void yyerror(char* s);
    int yylex();
    extern int yylineno;
    extern FILE* yyin;

    FILE* icg_quad_file;
    int temp_no = 1;
%}

%token T_ID T_NUM

%start START

%%
START : ASSGN   { 
                    printf("Valid syntax\n");
                    YYACCEPT;
                }

ASSGN : T_ID '=' E  { quad_code_gen($1, $3, "=", NULL); }

E : E '+' T     { char* temp = new_temp(); quad_code_gen(temp, $1, "+", $3); $$ = temp; }
  | E '-' T     { char* temp = new_temp(); quad_code_gen(temp, $1, "-", $3); $$ = temp; }
  | T           { $$ = $1; }
  
T : T '*' F     { char* temp = new_temp(); quad_code_gen(temp, $1, "*", $3); $$ = temp; }
  | T '/' F     { char* temp = new_temp(); quad_code_gen(temp, $1, "/", $3); $$ = temp; }
  | F           { $$ = $1; }

F : '(' E ')'   { $$ = $2; }
  | T_ID        { $$ = $1; }
  | T_NUM       { $$ = $1; }
%%

void yyerror(char* s)
{
    printf("Error :%s at %d \n",s,yylineno);
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Error opening input file");
        return 1;
    }

    yyin = input_file; // Set the input stream for the lexer
    icg_quad_file = fopen("icg_quad.txt", "w");
    if (!icg_quad_file) {
        perror("Error opening output file");
        fclose(input_file);
        return 1;
    }

    yyparse();

    fclose(input_file);
    fclose(icg_quad_file);
    return 0;
}