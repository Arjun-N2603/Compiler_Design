#ifndef QUAD_GENERATION_H
#define QUAD_GENERATION_H

#include <stdio.h>

extern FILE* icg_quad_file;  // Pointer to the output file for quadruples
extern int temp_no;          // Variable to keep track of current temporary count

void quad_code_gen(char* a, char* b, char* op, char* c);
char* new_temp();

#endif