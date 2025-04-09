CC = gcc
YACC = bison -d
LEX = flex
CFLAGS = -Wall -Wno-unused-function

EXE = parser
OBJS = parser.tab.c lex.yy.c abstract_syntax_tree.o

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE)

abstract_syntax_tree.o: abstract_syntax_tree.c abstract_syntax_tree.h
	$(CC) $(CFLAGS) -c abstract_syntax_tree.c

parser.tab.c parser.tab.h: parser.y
	$(YACC) parser.y

lex.yy.c: lexer.l parser.tab.h
	$(LEX) lexer.l

clean:
	rm -f $(EXE) parser.tab.c parser.tab.h lex.yy.c *.o

# Sample run commands - use these to run the parser
run1: $(EXE)
	./$(EXE) test_input_1.c

run2: $(EXE)
	./$(EXE) test_input_2.c

run3: $(EXE)
	./$(EXE) test_input_3.c

run4: $(EXE)
	./$(EXE) test_input_4.c

# Help text explaining usage
help:
	@echo "Usage:"
	@echo "  make run1 - Parse test_input_1.c"
	@echo "  make run2 - Parse test_input_2.c"
	@echo "  make run3 - Parse test_input_3.c" 
	@echo ""
	@echo "Or directly: ./$(EXE) <input_file>"
