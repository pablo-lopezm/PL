%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_logic.h"  // Lógica del juego
extern int yylex();
extern int yyparse();
void yyerror(const char *s);
%}

%union {
    char* sval;
}

%token <sval> SALIR REINICIAR PREGUNTA LISTA NOMBRE TIENE ES

%%
// Gramática principal
inicio:
    linea
    ;

linea:
    comandos 
    | preguntas 
    | intentos 
    | error {
        fprintf(stderr, "No entendí tu pregunta. Inténtalo nuevamente.\n");

    }
    ;

comandos:
    REINICIAR { reiniciar_juego(); }
    | SALIR { salir_juego();}
    | LISTA { mostrar_lista_personajes(); }
    ;

preguntas:
    PREGUNTA TIENE NOMBRE NOMBRE '?'  {
        manejar_pregunta($3, $4);
    }
    ;

intentos:
    PREGUNTA ES NOMBRE '?'  {
        manejar_adivinanza($3);
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
