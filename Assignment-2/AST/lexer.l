%{
    #include <stdio.h>
    #include "abstract_syntax_tree.h"  // Include types first
    #include "parser.tab.h"            // Then include parser definitions
    extern void yyerror(char* s);
%}

/* Regular definitions */
digit	[0-9]
letter	[a-zA-Z]
id	{letter}({letter}|{digit})*
digits	{digit}+
opFraction	(\.{digits})?
opExponent	([Ee][+-]?{digits})?
number	{digits}{opFraction}{opExponent}
%option yylineno
%option noyywrap

%%
\/\/(.*) ; // ignore comments
[ \t\r\n]+ ; // ignore whitespaces - handle multiple whitespace chars

"do"        { yylval.text = strdup(yytext); return T_DO; }
"while"     { yylval.text = strdup(yytext); return T_WHILE; }
"if"        { yylval.text = strdup(yytext); return T_IF; }
"else"      { yylval.text = strdup(yytext); return T_ELSE; }

"<="        { yylval.text = strdup(yytext); return T_LE; }
">="        { yylval.text = strdup(yytext); return T_GE; }
"=="        { yylval.text = strdup(yytext); return T_EQ; }
"!="        { yylval.text = strdup(yytext); return T_NE; }
"<"         { yylval.text = strdup(yytext); return T_LT; }
">"         { yylval.text = strdup(yytext); return T_GT; }

"("         { return *yytext; }
")"         { return *yytext; }
"{"         { return *yytext; }
"}"         { return *yytext; }
"."         { return *yytext; }
","         { return *yytext; }
"*"         { return *yytext; }
"+"         { return *yytext; }
";"         { return *yytext; }
"-"         { return *yytext; }
"/"         { return *yytext; }
"="         { return *yytext; }

{number}    {
              yylval.text = strdup(yytext);
              return T_NUM;
            }
{id}        {
              yylval.text = strdup(yytext);
              return T_ID;
            }
.           { printf("Unrecognized character: %s\n", yytext); } // Print unrecognized chars for debugging
%%