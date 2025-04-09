%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "quad_generation.h"

	#define YYSTYPE char*

	void yyerror(char* s);
	int yylex();
	extern int yylineno;

	FILE* icg_quad_file;
	int temp_no = 1;
	
	// For storing label information
	char* if_true_label;
	char* if_false_label;
	char* if_end_label;
	char* loop_start_label;
%}

%token T_ID T_NUM T_IF T_ELSE T_DO T_WHILE
%token T_LE T_GE T_EQ T_NE

/* Specify precedence to resolve the dangling else problem */
%nonassoc IFX
%nonassoc T_ELSE

/* specify start symbol */
%start START

%%
START : STMT_LIST	{ 
						printf("\n");
						print_three_address_code();
						printf("\n");
						print_quad_table();
						printf("Valid syntax\n");
	 					YYACCEPT;
	 				}
	;

STMT_LIST : STMT STMT_LIST { }
	| /* epsilon */ { }
	;

STMT : IF_STMT
    | DO_WHILE_STMT
    | ASSGN ';' { }
    ;

IF_STMT : T_IF '(' CONDITION ')' '{' {
			// Generate labels
			if_true_label = new_label();
			if_false_label = new_label();
			
			// Jump to true part if condition is true
			add_quad("If", $3, "", if_true_label);
			// Otherwise go to false part
			add_quad("goto", "", "", if_false_label);
			// Mark the beginning of true part
			add_quad("Label", "", "", if_true_label);
		} 
		STMT_LIST '}' ELSE_PART
    ;

ELSE_PART : T_ELSE '{' {
			// Generate end label for if-else
			if_end_label = new_label();
			// After true block, go to end
			add_quad("goto", "", "", if_end_label);
			// Mark the beginning of false part
			add_quad("Label", "", "", if_false_label);
		}
		STMT_LIST '}' {
			// End of if-else statement
			add_quad("Label", "", "", if_end_label);
			}
    | %prec IFX {
			// End of if statement without else
			add_quad("Label", "", "", if_false_label);
		}
    ;

DO_WHILE_STMT : T_DO '{' {
			// Generate label for loop start
			loop_start_label = new_label();
			// Mark the beginning of loop
			add_quad("Label", "", "", loop_start_label);
		}
		STMT_LIST '}' T_WHILE '(' CONDITION ')' ';' {
			// If condition is true, jump back to loop start
			add_quad("If", $7, "", loop_start_label);
			}
    ;

CONDITION : T_ID REL T_ID {
				char* temp = new_temp();
				add_quad($2, $1, $3, temp);
				$$ = temp;
			}
	| T_ID REL T_NUM {
				char* temp = new_temp();
				add_quad($2, $1, $3, temp);
				$$ = temp;
			}
	| T_NUM REL T_ID {
				char* temp = new_temp();
				add_quad($2, $1, $3, temp);
				$$ = temp;
			}
	;

REL : '<' { $$ = "<"; }
	| '>' { $$ = ">"; }
	| T_LE { $$ = "<="; }
	| T_GE { $$ = ">="; }
	| T_EQ { $$ = "=="; }
	| T_NE { $$ = "!="; }
	;

/* Grammar for assignment */
ASSGN : T_ID '=' E	{ quad_code_gen($1, $3, "=", ""); }
	;

/* Expression Grammar */
E : E '+' T 	{
					char* temp = new_temp();
					quad_code_gen(temp, $1, "+", $3);
					$$ = temp;
				}
	| E '-' T 	{
					char* temp = new_temp();
					quad_code_gen(temp, $1, "-", $3);
					$$ = temp;
				}
	| T 		{ $$ = $1; }
	;
	
T : T '*' F 	{
					char* temp = new_temp();
					quad_code_gen(temp, $1, "*", $3);
					$$ = temp;
				}
	| T '/' F 	{
					char* temp = new_temp();
					quad_code_gen(temp, $1, "/", $3);
					$$ = temp;
				}
	| F 		{ $$ = $1; }
	;

F : '(' E ')' 	{ $$ = $2; }
	| T_ID 		{ $$ = $1; }
	| T_NUM 	{ $$ = $1; }
	;

%%

/* error handling function */
void yyerror(char* s)
{
	printf("Error: %s at line %d\n", s, yylineno);
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
	extern FILE* yyin;
	yyin = input_file;
	
	// Parse the input
	yyparse();
	
	// Clean up
	fclose(input_file);
	
	return 0;
}