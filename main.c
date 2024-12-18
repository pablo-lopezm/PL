#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_logic.h"  // Lógica del juego

extern int yylex();
extern int yyparse();

void limpiar_buffer() {
    // Limpiar el buffer de entrada hasta el final de la línea
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int main() {
    // Inicializar personajes o cualquier estado necesario para el juego
    inicializar_personajes();
    reiniciar_juego();

    printf("Bienvenido a '¿Quién es quién?'\n");
    printf("Usa comandos como:\n");
    printf("- Pregunta sobre atributos: ¿El personaje tiene cabello negro?\n");
    printf("- Intenta adivinar: ¿El personaje es Mario?\n");
    printf("- Ver lista: lista\n");
    printf("- Reiniciar el juego: reiniciar\n");
    printf("- Salir: salir\n");

    while (1) {
        printf("\n> "); 
        if (yyparse() != 0) {
            limpiar_buffer();
        }
    }

    printf("Gracias por jugar. ¡Hasta luego!\n");
    return 0;
}
