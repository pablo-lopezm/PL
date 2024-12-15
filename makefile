# Nombres de archivos
LEXER=lexer.l
PARSER=parser.y
MAIN=main.c
GAME_LOGIC=game_logic.c
EXECUTABLE=quien_es_quien

# Archivos generados por Bison y Flex
PARSER_C=parser.tab.c
PARSER_H=parser.tab.h
LEXER_C=lex.yy.c

# Compilador y banderas
CC=gcc
CFLAGS=-Wall -Wextra -g

# Objetivo predeterminado
all: $(EXECUTABLE)

# Regla para generar el ejecutable
$(EXECUTABLE): $(PARSER_C) $(LEXER_C) $(MAIN) $(GAME_LOGIC)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(PARSER_C) $(LEXER_C) $(MAIN) $(GAME_LOGIC)

# Generar el código C del parser
$(PARSER_C) $(PARSER_H): $(PARSER)
	bison -d $(PARSER)

# Generar el código C del lexer
$(LEXER_C): $(LEXER)
	flex $(LEXER)

# Limpiar archivos generados
clean:
	rm -f $(PARSER_C) $(PARSER_H) $(LEXER_C) $(EXECUTABLE)

# Regla para ejecutar el programa
run: $(EXECUTABLE)
	./$(EXECUTABLE)
