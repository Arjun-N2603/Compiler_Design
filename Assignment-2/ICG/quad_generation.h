extern FILE* icg_quad_file;		//pointer to the output file
extern int temp_no;				//variable to keep track of current temporary count
extern int label_no;            //variable to keep track of current label count

void quad_code_gen(char* a, char* b, char* op, char* c);
char* new_temp();
char* new_label();
void emit_3ac(char* op, char* arg1, char* arg2, char* result);
void add_quad(char* op, char* arg1, char* arg2, char* result);
void print_three_address_code();
void print_quad_table();