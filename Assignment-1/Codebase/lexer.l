%{
#include <stdio.h>
#include "y.tab.h"
extern int yylineno;
void yyerror(char *s); // Declaration of yyerror (no definition here)
#include <stdlib.h>
#include <string.h>

// Function to truncate identifier and report error
void truncate_identifier(char *identifier);

// Track column number
int column = 1;

%}

DIGIT   [0-9]
LETTER  [a-zA-Z_]
ID      {LETTER}({LETTER}|{DIGIT})*
INT_LITERAL     {DIGIT}+
FLOAT_LITERAL   {DIGIT}+\.{DIGIT}+([eE][+-]?{DIGIT}+)?
COMMENT_SINGLE  "//".*
COMMENT_MULTI_START "/*"
COMMENT_MULTI_END   "*/"
INCLUDE_DIRECTIVE   "#include"[ \t]*[<"][^>]+[>"]|[#include][ \t]*["]([^"])+["]

%%

"int"           { return T_INT; }
"float"         { return T_FLOAT; }
"char"          { return T_CHAR; }
"double"        { return T_DOUBLE; }
"if"            { return T_IF; }
"while"         { return T_WHILE; }
"for"           { return T_FOR; }
"do"            { return T_DO; }
"else"          { return T_ELSE; }
"switch"        { return T_SWITCH; }
"case"          { return T_CASE; }
"break"         { return T_BREAK; }
"default"       { return T_DEFAULT; }
"main"          { return T_MAIN; }
"+"             { return '+'; }
"-"             { return '-'; }
"*"             { return '*'; }
"/"             { return '/'; }
"("             { return '('; }
")"             { return ')'; }
"{"             { return '{'; }
"}"             { return '}'; }
"["             { return '['; }
"]"             { return ']'; }
";"             { return ';'; }
","             { return ','; }
"="             { return '='; }
"<="            { return T_LE; }
">="            { return T_GE; }
"!="            { return T_NE; }
"=="            { return T_EQ; }
"&&"            { return T_AND; }
"||"            { return T_OR; }
"!"             { return '!'; }
"++"            { return T_INC; }
"--"            { return T_DEC; }
"%"             { return '%'; }
"<"             { return '<'; }
">"             { return '>'; }
"\'"            { return T_CHAR_QUOTE; }
{ID}            { if (strlen(yytext) > 31) { truncate_identifier(yytext); } yylval.sval = strdup(yytext); return T_ID; }
{INT_LITERAL}   { yylval.sval = strdup(yytext); return T_NUM; }
{FLOAT_LITERAL} { yylval.sval = strdup(yytext); return T_NUM; }
{COMMENT_SINGLE} { column += strlen(yytext); /* Ignore single-line comments */ }
{COMMENT_MULTI_START} {
    int c;
    column += 2; // Account for "/*"
    while (1) {
        c = input();
        if (c == EOF) {
            yyerror("Unterminated comment at end of file");
            return 0; // Or handle EOF appropriately
        }
        column++;
        if (c == '*') {
            if (input() == '/') {
                column += 2; // Account for "*/"
                break; // Comment ends
            } else {
                yyless(1); // Put back the character after '*' if it's not '/'
            }
        }
        if (c == '\n') {
            yylineno++;
            column = 1;
        }
    }
}
{INCLUDE_DIRECTIVE} { column += strlen(yytext); /* Ignore include directives */ }
[ \t]+          { column += strlen(yytext); /* ignore whitespace */ }
\n              { yylineno++; column = 1; }
.               { yyerror("Invalid character"); column++; }

%%

int yywrap(void) {
    return 1;
}

void truncate_identifier(char *identifier) {
    printf("Warning: Identifier '%s' is longer than 31 characters. Truncating to '%.31s' at line %d, column %d.\n",
           identifier, identifier, yylineno, column);
    identifier[31] = '\0'; // Truncate the identifier
}

// Error function is only declared in lexer, defined in parser.y
// void yyerror(char *s) {
//     fprintf(stderr, "Error: %s at line %d, column %d\n", s, yylineno, column);
// }