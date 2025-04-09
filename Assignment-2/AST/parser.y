%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	// Forward declarations for the types used in %union
	struct expression_node;
	struct statement_node;
	typedef struct expression_node expression_node;
	typedef struct statement_node statement_node;
	
	#include "abstract_syntax_tree.h"
	
	void yyerror(char* s);
	int yylex();
	extern int yylineno;
	
	// For debugging
	extern FILE* yyin;
	extern char* yytext;
%}

%union
{
	char* text;
	expression_node* exp_node;
	statement_node* stmt_node;
}

%token <text> T_ID T_NUM
%token <text> T_DO T_WHILE T_IF T_ELSE
%token <text> T_LT T_GT T_LE T_GE T_EQ T_NE

%type <exp_node> E T F ASSGN
%type <text> REL
%type <exp_node> CONDITION 
%type <stmt_node> START STMT STMT_LIST

/* specify start symbol */
%start START

%%
START : STMT_LIST	{ 
		$$ = $1; 
		flat_display_statement_tree($$, 1); 
		printf("\n\nValid syntax\n"); 
		YYACCEPT; 
	}
	| ASSGN {
		// Original AST display for backward compatibility with old test files
		$$ = init_assignment_node($1, NULL);
		printf("%s\n", $1->val);
		display_exp_tree($1->left);
		display_exp_tree($1->right);
		printf("\nValid syntax\n");
		YYACCEPT;
	}
	;

STMT_LIST : STMT STMT_LIST { 
		if ($1 != NULL) {
			statement_node* temp = $1;
			while (temp->next != NULL) {
				temp = $1;
			}
			temp->next = $2;
			$$ = $1;
		} else {
			$$ = $2;
		}
	}
	| /* empty */ { $$ = NULL; }
	;

STMT : T_DO '{' STMT_LIST '}' T_WHILE '(' CONDITION ')' ';' {
		$$ = init_do_while_node($7, $3, NULL);
	}
	| T_IF '(' CONDITION ')' '{' STMT_LIST '}' T_ELSE '{' STMT_LIST '}' {
		$$ = init_if_else_node($3, $6, $10, NULL);
	}
	| T_IF '(' CONDITION ')' '{' STMT_LIST '}' {
		$$ = init_if_else_node($3, $6, NULL, NULL);
	}
	| ASSGN ';' {
		$$ = init_assignment_node($1, NULL);
	}
	;

CONDITION : T_ID REL T_ID {
		$$ = init_exp_node($2, init_exp_node($1, NULL, NULL), init_exp_node($3, NULL, NULL));
	}
	| T_ID REL T_NUM {
		$$ = init_exp_node($2, init_exp_node($1, NULL, NULL), init_exp_node($3, NULL, NULL)); 
	}
	| T_NUM REL T_ID {
		$$ = init_exp_node($2, init_exp_node($1, NULL, NULL), init_exp_node($3, NULL, NULL));
	}
	;

REL : T_LT { $$ = strdup("<"); }
	| T_GT { $$ = strdup(">"); }
	| T_LE { $$ = strdup("<="); }
	| T_GE { $$ = strdup(">="); }
	| T_EQ { $$ = strdup("=="); }
	| T_NE { $$ = strdup("!="); }
	;

ASSGN : T_ID '=' E	{ $$ = init_exp_node("=", init_exp_node($1, NULL, NULL), $3); }
	;

/* Expression Grammar */
E : E '+' T 	{ $$ = init_exp_node("+", $1, $3); }
  | E '-' T 	{ $$ = init_exp_node("-", $1, $3); }
  | T 		{ $$ = $1; }
  ;
	
T : T '*' F 	{ $$ = init_exp_node("*", $1, $3); }
  | T '/' F 	{ $$ = init_exp_node("/", $1, $3); }
  | F 		{ $$ = $1; }
  ;

F : '(' E ')' 	{ $$ = $2; }
  | T_ID	{ $$ = init_exp_node($1, NULL, NULL); }
  | T_NUM	{ $$ = init_exp_node($1, NULL, NULL); }
  ;

%%

/* error handling function */
void yyerror(char* s)
{
	printf("Error :%s at %d (near '%s')\n", s, yylineno, yytext);
}


/* main function - calls the yyparse() function which will in turn drive yylex() as well */
int main(int argc, char* argv[])
{
	if (argc < 2) {
		printf("Usage: %s <input_file>\n", argv[0]);
		return 1;
	}
	
	// Open the input file
	FILE* input_file = fopen(argv[1], "r");
	if (!input_file) {
		printf("Error: Could not open input file %s\n", argv[1]);
		return 1;
	}
	
	// Set yyin to use the input file
	yyin = input_file;
	
	// Print parsing of the file
	printf("Parsing file: %s\n", argv[1]);
	
	// Parse the input
	yyparse();
	
	// Clean up
	fclose(input_file);
	
	return 0;
}