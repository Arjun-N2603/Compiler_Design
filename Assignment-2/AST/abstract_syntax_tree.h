typedef struct expression_node
{
    char* val;
    struct expression_node* left;
    struct expression_node* right;
}expression_node;

// Statement node with condition and body parts
typedef struct statement_node
{
    char* type;                 // "if-else" or "do-while"
    struct expression_node* condition;
    struct statement_node* if_body;
    struct statement_node* else_body;
    struct statement_node* next;  // For statement sequences
}statement_node;

expression_node* init_exp_node(char* val, expression_node* left, expression_node* right);
statement_node* init_if_else_node(expression_node* condition, statement_node* if_body, statement_node* else_body, statement_node* next);
statement_node* init_do_while_node(expression_node* condition, statement_node* body, statement_node* next);
statement_node* init_assignment_node(expression_node* assign_exp, statement_node* next);

void display_exp_tree(expression_node* exp_node);
void display_statement_tree(statement_node* stmt_node, int indent_level);
void flat_display_statement_tree(statement_node* stmt_node, int is_first);
void flat_display_exp_node(expression_node* exp_node);