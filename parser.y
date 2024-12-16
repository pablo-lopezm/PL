%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_logic.h"  // Lógica del juego

extern int yylex();
extern int yyparse();
extern char* yytext;  // Contiene el texto del token que se está procesando
extern int yylineno;  // Número de línea actual

void yyerror(const char *s);
%}

%union {
    char* sval;
}

%token <sval> SALIR REINICIAR PREGUNTA LISTA NOMBRE TIENE ES ISIGN

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
        fprintf(stderr, "No entendí tu pregunta en la línea %d cerca de '%s'. Inténtalo nuevamente.\n", yylineno, yytext);
    }
    ;

comandos:
    REINICIAR { reiniciar_juego(); return 0;}
    | SALIR { salir_juego(); }
    | LISTA { mostrar_lista_personajes(); return 0;}
    ;

preguntas:
    PREGUNTA TIENE NOMBRE NOMBRE ISIGN  {
        manejar_pregunta($3, $4); return 0;
    }
    ;

intentos:
    PREGUNTA ES NOMBRE ISIGN  {
        manejar_adivinanza($3); return 0;
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis en la línea %d cerca de '%s': %s\n", yylineno, yytext, s);
}
