#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_logic.h"  // Lógica del juego

extern int yylex();
extern int yyparse();

int main() {
    // Inicializar personajes o cualquier estado necesario para el juego
    inicializar_personajes();

    printf("Bienvenido a '¿Quién es quién?'\n");
    printf("Usa comandos como:\n");
    printf("- Pregunta sobre atributos: ¿El personaje tiene cabello negro?\n");
    printf("- Intenta adivinar: ¿El personaje es Mario?\n");
    printf("- Ver lista: lista\n");
    printf("- Reiniciar el juego: reiniciar\n");
    printf("- Salir: salir\n");

    while (1) {
        printf("\n> ");  // Indicador de entrada
        if (yyparse() != 0) {
            // Si `yyparse` encuentra un error crítico, salimos del bucle
            fprintf(stderr, "Ocurrió un error. Finalizando el programa.\n");
            break;
        }
    }

    printf("Gracias por jugar. ¡Hasta luego!\n");
    return 0;
}
