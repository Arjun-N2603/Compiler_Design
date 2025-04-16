%{
#include "y.tab.h"
#include <stdio.h>
#include <string.h>
extern int line_number;
%}

DIGIT   [0-9]
LETTER  [a-zA-Z]
ID      {LETTER}({LETTER}|{DIGIT})*
NUM     {DIGIT}+(\.{DIGIT}+)?([eE][+-]?{DIGIT}+)?
%%

"int"           { return INT; }
"float"         { return FLOAT; }
"double"        { return DOUBLE; }
"char"          { return CHAR; }
"void"          { return VOID; }
"if"            { return IF; }
"else"          { return ELSE; }
"for"           { return FOR; }
"while"         { return WHILE; }
"do"            { return DO; }
"switch"        { return SWITCH; }
"case"          { return CASE; }
"default"       { return DEFAULT; }
"break"         { return BREAK; }
"continue"      { return CONTINUE; }
"return"        { return RETURN; }
"main"          { return MAIN; } // Recognize main function
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return TIMES; }
"/"             { return DIVIDE; }
"!"             { return NOT; }
"++"            { return INC; }
"--"            { return DEC; }

"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
"["             { return LBRACKET; }
"]"             { return RBRACKET; }
";"             { return SEMICOLON; }
","             { return COMMA; }
":"             { return COLON; }
"="             { return ASSIGN; }
"=="            { return EQ; }
"!="            { return NEQ; }
"<"             { return LT; }
">"             { return GT; }
"<="            { return LTE; }
">="            { return GTE; }
"&&"            { return AND; }
"||"            { return OR; }
{ID}            { yylval.str = strdup(yytext); return ID; }
{NUM}           { yylval.str = strdup(yytext); return NUM; }
"\'"(\\.|[^'\\])"\'"   { yylval.str = strdup(yytext); return NUM; }
"//".*          { /* Ignore single-line comments */ }
"/*"[^*]*"*/" { /* Ignore multi-line comments */ }
[ \t]           { /* Ignore spaces and tabs */ }
\n              { line_number++; }
.               { fprintf(stderr, "Error: Illegal character '%s' at line %d\n", yytext, line_number); }

%%

int yywrap() {
    return 1;
}