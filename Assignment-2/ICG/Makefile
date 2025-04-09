CC = gcc
YACC = bison -d
LEX = flex
CFLAGS = -Wall -Wno-unused-function

EXE = parser
OBJS = parser.tab.c lex.yy.c quad_generation.c

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE)

quad_generation.o: quad_generation.c quad_generation.h
	$(CC) $(CFLAGS) -c quad_generation.c

parser.tab.c parser.tab.h: parser.y
	$(YACC) parser.y

lex.yy.c: lexer.l parser.tab.h
	$(LEX) lexer.l

clean:
	rm -f $(EXE) parser.tab.c parser.tab.h lex.yy.c *.o

# Sample run commands
run1:
	./$(EXE) test_input_1.c

run2:
	./$(EXE) test_input_2.c

# Help text explaining usage
help:
	@echo "Usage:"
	@echo "  make run1 - Process test_input_1.c"
	@echo "  make run2 - Process test_input_2.c"
	@echo ""
	@echo "Or directly: ./$(EXE) <input_file>"
