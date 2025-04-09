%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylineno;
extern FILE *yyin;
extern int yyparse();
void yyerror(char *s);
int yylex();
extern int column;
extern char *yytext;
int skip_to_sync(void);
int has_errors = 0;
%}

%union {
    char *sval;
}

%token <sval> T_ID T_NUM
%token T_INT T_FLOAT T_CHAR T_DOUBLE T_IF T_WHILE T_FOR T_DO T_ELSE T_SWITCH T_CASE T_BREAK T_DEFAULT T_MAIN
%token T_LE T_GE T_NE T_EQ T_AND T_OR T_NOT T_INC T_DEC T_CHAR_QUOTE

%%

P : T_INT T_MAIN '(' ')' '{' S '}'
  | error { has_errors = 1; skip_to_sync(); yyerrok; if (yylex() == 0) YYABORT; }
  ;

S : VarDeclr
  | AssignExpr ';' S
  | AssignExpr error { has_errors = 1; printf("Error: missing semicolon, line number: %d, token: %s\n", yylineno, yytext); skip_to_sync(); yyerrok; if (yylex() == 0) YYABORT; } S
  | T_IF '(' COND ')' '{' S '}' el S
  | T_IF '(' COND ')' S
  | T_IF '(' COND ')' '{' S '}' T_ELSE T_IF '(' COND ')' '{' S '}' el S
  | T_WHILE '(' COND ')' '{' S '}' S
  | T_WHILE '(' COND ')' S
  | T_DO '{' S '}' T_WHILE '(' COND ')' ';' S
  | T_FOR '(' ForInit ';' COND ';' Update ')' '{' S '}' S
  | Type T_ID '[' T_NUM ']' B ';' S
  | Type T_ID '[' T_NUM ']' '=' '{' Arrayelements '}' ';' S
  | T_SWITCH '(' D ')' '{' swt '}' S
  | /* empty */
  | error { has_errors = 1; printf("Error: syntax error, line number: %d, token: %s\n", yylineno, yytext); skip_to_sync(); yyerrok; if (yylex() == 0) YYABORT; } S
  ;

swt : T_CASE D ':' S T_BREAK ';' swt
    | T_DEFAULT ':' S
    | /* empty */
    ;

D : T_ID
  | T_NUM
  ;

el : T_ELSE '{' S '}'
   | /* empty */
   | T_ELSE '(' error { has_errors = 1; printf("Error: syntax error, line number: %d, token: else\n", yylineno); skip_to_sync(); yyerrok; }
   | T_ELSE error { has_errors = 1; printf("Error: dangling else, line number: %d, token: else\n", yylineno); skip_to_sync(); yyerrok; }
   ;

Arrayelements : T_NUM ',' Arrayelements
              | T_NUM
              ;

B : '[' T_NUM ']' B
  | /* empty */
  ;

Update : AssignExpr
       | /* empty */
       ;

M : T_INC
  | T_DEC
  ;

COND : E
     | error { has_errors = 1; printf("Error: syntax error, line number: %d, token: %s\n", yylineno, yytext); skip_to_sync(); yyerrok; if (yylex() == 0) YYABORT; }
     ;

ForInit : Type InitDeclarator
        | AssignExpr
        | /* empty */
        ;

AssignExpr : T_ID '=' E
           | T_ID '[' E ']' '=' E
           | T_ID M
           | M T_ID
           | Type T_ID '=' T_CHAR_QUOTE T_ID T_CHAR_QUOTE
           | T_ID '=' T_CHAR_QUOTE T_ID T_CHAR_QUOTE
           ;

E : E '+' T
  | E '-' T
  | E REL T
  | E LOG T
  | T
  ;

REL : '>'
    | '<'
    | T_LE
    | T_GE
    | T_NE
    | T_EQ
    ;

LOG : T_AND
    | T_OR
    | '!'
    ;

T : T '*' F
  | T '/' F
  | T '%' F
  | F
  ;

F : '(' E ')'
  | T_ID
  | T_NUM
  | M F
  ;

VarDeclr : Type ListVar ';' S
         ;

ListVar  : InitDeclarator
         | ListVar ',' InitDeclarator
         ;

InitDeclarator : T_ID
               | T_ID '=' E
               ;

Type : T_INT
     | T_FLOAT
     | T_CHAR
     | T_DOUBLE
     ;

%%

void yyerror(char *s) {
    if (strcmp(s, "Unrecognized token") == 0) {
        printf("Error: Unrecognized token, line number: %d, token: %s\n", yylineno, yytext);
    }
}

int skip_to_sync(void) {
    int c;
    int brace_count = 0;
    while ((c = yylex()) != 0) {
        if (c == '{') {
            brace_count++;
        } else if (c == '}') {
            brace_count--;
            if (brace_count < 0) {
                printf("Error: unmatched closing brace, line number: %d, token: %s\n", yylineno, yytext);
                has_errors = 1;
                return c;
            }
        } else if (c == ';' && brace_count == 0) {
            return c;
        } else if (c == ':' && brace_count == 0) {
            printf("Error: Unrecognized token, line number: %d, token: %s\n", yylineno, yytext);
            has_errors = 1;
            return c;
        } else if (c == T_ELSE && brace_count == 0) {
            return c;
        } else if (c == T_IF && brace_count == 0) {
            return c;
        } else if (c == T_WHILE && brace_count == 0) {
            return c;
        }
    }
    if (brace_count > 0) {
        printf("Error: %d unmatched opening brace(s), line number: %d\n", brace_count, yylineno);
        has_errors = 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    has_errors = 0;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (!fp) {
            perror("Error opening input file");
            exit(1);
        }
        yyin = fp;
    }
    yylineno = 1;
    column = 1;
    if (!yyparse() && !has_errors)
        printf("Valid syntax\n");
    else
        printf("Parsing failed.\n");
    if (argc > 1)
        fclose(fp);
    return 0;
}