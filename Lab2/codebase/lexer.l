%{
    #define YYSTYPE char*
    #include "y.tab.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    extern void yyerror(const char *);
    extern int yylineno;
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

%%
\/\/(.*) ;
[\t] ;
(\r\n|\n|\r) { yylineno;}
"int" 		{ yylval=strdup(yytext); return T_INT;}
"char"		{ yylval=strdup(yytext); return T_CHAR;}
"double"	{ yylval=strdup(yytext); return T_DOUBLE;}
"float"		{ yylval=strdup(yytext); return T_FLOAT;}
"while" 	{return T_WHILE;}
"if"		{return T_IF;}
"else"		{return T_ELSE;}
"do" 		{return T_DO;}
"#include" 	{return T_INCLUDE;}
"main" 		{return T_MAIN;}
\".*\"		{yylval=strdup(yytext); return T_STRLITERAL; }
"=="		{return T_EQCOMP;}
"!="		{return T_NOTEQUAL;}
">="        	{return T_GREATEREQ;}
"<="        	{return T_LESSEREQ;}
"("		{return *yytext;}
")"		{return *yytext;}
"."         	{return *yytext;}
","         	{return *yytext;}
"{"         	{return *yytext;}
"}"         	{return *yytext;}
"*"         	{return *yytext;}
"+"         	{return *yytext;}
";"         	{return *yytext;}
"-"         	{return *yytext;}
"/"         	{return *yytext;}
"="         	{return *yytext;}
">"         	{return *yytext;}
"<"         	{return *yytext;}
{number}	{
			yylval=strdup(yytext);
			return T_NUM;
		}
{id}\.h	{return T_HEADER;}
{id}        	{
			yylval=strdup(yytext);
			return T_ID;
		}
.		{}
%%
int yywrap() {
    return 1;
}