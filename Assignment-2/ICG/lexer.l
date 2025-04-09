%{
    #define YYSTYPE char*
    #include <unistd.h>
    #include "parser.tab.h"
    #include <stdio.h>
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
[\t\n ] ; // ignore whitespaces (added space to whitespace list)
"if"        { return T_IF; }
"else"      { return T_ELSE; }
"do"        { return T_DO; }
"while"     { return T_WHILE; }
"<="        { return T_LE; }
">="        { return T_GE; }
"=="        { return T_EQ; }
"!="        { return T_NE; }
"("		    { return *yytext; }
")"		    { return *yytext; }
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
">"         { return *yytext; }
"<"         { return *yytext; }
{number}	{
			yylval = strdup(yytext);
			return T_NUM;
		}
{id}        {
			yylval = strdup(yytext);
			return T_ID;
		}
.		{} // anything else => ignore
%%