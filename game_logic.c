#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "game_logic.h"

// Definir la estructura con los atributos solicitados
typedef struct {
    char nombre[50];
    struct {
        char color[20];
        char largura[20];
        char tipo[20];
    } cabello;
    struct {
        char color[20];
        char tipo[20];
    } vello_facial;
    char nariz[20];
    char labios[20];
    char ojos[20];
    char complemento[50];
    char sexo[10];
} Personaje;

// Variables globales
Personaje personajes[10];
int num_personajes = 0;
Personaje* personaje_actual = NULL;

// Función para inicializar los personajes
void inicializar_personajes() {
    num_personajes = 10;
    Personaje personajes_inicializados[10] = {
        {"Alex", {"negro", "corto", "liso"}, {"negro", "bigote"}, "pequeña", "gruesos", "marrones", "", "hombre"},
        {"Alfred", {"pelirrojo", "largo", "liso"}, {"pelirrojo", "bigote"}, "pequeña", "finos", "azules", "", "hombre"},
        {"Anita", {"rubio", "largo", "liso"}, {"", ""}, "pequeña", "finos", "azules", "lazos", "mujer"},
        {"Anne", {"castaño", "largo", "rizado"}, {"", ""}, "grande", "finos", "marrones", "pendientes", "mujer"},
        {"Bernard", {"castaño", "corto", "liso"}, {"", ""}, "grande", "finos", "marrones", "gorro", "hombre"},
        {"David", {"rubio", "corto", "liso"}, {"rubia", "barba"}, "pequeña", "gruesos", "marrones", "", "hombre"},
        {"Eric", {"rubio", "corto", "liso"}, {"", ""}, "pequeña", "gruesos", "negros", "sombrero", "hombre"},
        {"Frans", {"pelirrojo", "corto", "rizado"}, {"", ""}, "pequeña", "finos", "marrones", "", "hombre"},
        {"George", {"blanco", "corto", "liso"}, {"", ""}, "pequeña", "gruesos", "marrones", "sombrero", "hombre"},
        {"Maria", {"castaño", "largo", "liso"}, {"", ""}, "pequeña", "gruesos", "marrones", "gorro", "mujer"}
    };

    for (int i = 0; i < num_personajes; i++) {
        personajes[i] = personajes_inicializados[i];
    }
}

// Función para evaluar condiciones
int evaluar_condicion(const char* atributo, const char* valor) {
    if (personaje_actual == NULL) {
        return 0; // No hay personaje seleccionado
    }

    if (strcmp(atributo, "cabello color") == 0) {
        return strcmp(personaje_actual->cabello.color, valor) == 0;
    } else if (strcmp(atributo, "cabello largura") == 0) {
        return strcmp(personaje_actual->cabello.largura, valor) == 0;
    } else if (strcmp(atributo, "cabello tipo") == 0) {
        return strcmp(personaje_actual->cabello.tipo, valor) == 0;
    } else if (strcmp(atributo, "vello facial color") == 0) {
        return strcmp(personaje_actual->vello_facial.color, valor) == 0;
    } else if (strcmp(atributo, "vello facial tipo") == 0) {
        return strcmp(personaje_actual->vello_facial.tipo, valor) == 0;
    } else if (strcmp(atributo, "nariz") == 0) {
        return strcmp(personaje_actual->nariz, valor) == 0;
    } else if (strcmp(atributo, "labios") == 0) {
        return strcmp(personaje_actual->labios, valor) == 0;
    } else if (strcmp(atributo, "ojos") == 0) {
        return strcmp(personaje_actual->ojos, valor) == 0;
    } else if (strcmp(atributo, "complemento") == 0) {
        return strcmp(personaje_actual->complemento, valor) == 0;
    } else if (strcmp(atributo, "sexo") == 0) {
        return strcmp(personaje_actual->sexo, valor) == 0;
    } else {
        return 0; // Caso desconocido
    }
}

// Función para manejar preguntas
void manejar_pregunta(const char* atributo, const char* valor) {
    if (personaje_actual == NULL) {
        printf("Error: No hay un personaje seleccionado.\n");
        return;
    }

    if (strcmp(atributo, "cabello color") == 0) {
        printf("%s\n", strcmp(personaje_actual->cabello.color, valor) == 0 ? "Sí" : "No");
    } else if (strcmp(atributo, "sexo") == 0) {
        printf("%s\n", strcmp(personaje_actual->sexo, valor) == 0 ? "Sí" : "No");
    } else {
        printf("Atributo desconocido: %s.\n", atributo);
    }
}

// Función para manejar intentos de adivinanza
void manejar_adivinanza(const char* nombre) {
    printf("Intento: ¿El personaje es %s?\n", nombre);
    if (personaje_actual != NULL && strcmp(personaje_actual->nombre, nombre) == 0) {
        printf("¡Correcto! El personaje era %s.\n", personaje_actual->nombre);
        reiniciar_juego();
    } else {
        printf("No, el personaje no es %s. ¡Sigue intentando!\n", nombre);
    }
}

// Función para mostrar la lista de personajes
void mostrar_lista_personajes() {
    printf("Lista de personajes:\n");
    for (int i = 0; i < num_personajes; i++) {
        printf("- %s\n", personajes[i].nombre);
    }
}

// Función para eliminar un personaje por su índice
void eliminar_personaje(int indice) {
    if (indice < 0 || indice >= num_personajes) {
        printf("Error: Índice fuera de rango.\n");
        return;
    }

    for (int i = indice; i < num_personajes - 1; i++) {
        personajes[i] = personajes[i + 1];
    }
    num_personajes--;
}

// Función para eliminar un personaje por su nombre
void eliminar_personaje_por_nombre(const char* nombre) {
    for (int i = 0; i < num_personajes; i++) {
        if (strcmp(personajes[i].nombre, nombre) == 0) {
            if (strcmp(personaje_actual->nombre, nombre) == 0) {
                 printf("¡OH NO! Has eliminado a %s, que era el personaje seleccionado. Game over.\n¡Intentalo otra vez! \n\n", nombre);
                 reiniciar_juego();
                 return;
            }
            eliminar_personaje(i);
            printf("El personaje '%s' ha sido eliminado.\n", nombre);
            return;
        }
    }
    printf("Error: Personaje '%s' no encontrado.\n", nombre);
}

// Función para reiniciar el juego
void reiniciar_juego() {
    inicializar_personajes();
    srand(time(NULL));
    int indice = rand() % num_personajes;
    personaje_actual = &personajes[indice];
    printf("Un nuevo personaje ha sido seleccionado. ¡Comienza el juego!\n");
}

// Función para salir del juego
void salir_juego() {
    printf("Gracias por jugar. ¡Hasta luego!\n");
    exit(0);
}

void mostrar_ayuda() {
    printf("Comandos permitidos:\n");
    printf("  reiniciar                  - Reinicia el juego.\n");
    printf("  salir                      - Sale del juego.\n");
    printf("  lista                      - Muestra la lista de personajes.\n");
    printf("  elimina a <nombre>         - Elimina un personaje por su nombre.\n");
    printf("  ayuda                      - Muestra esta ayuda.\n\n");

    printf("Ejemplos de frases permitidas para preguntas:\n");
    printf("   - ¿El personaje tiene cabello castaño?\n");
    printf("   - ¿El personaje tiene labios gruesos?\n");
    printf("   - ¿El personaje lleva sombrero?\n");
    printf("   - ¿El personaje es mujer?\n");
    printf("\nEjemplos de frases permitidas que incorporan disyunciones y conjunciones:\n");
    printf("   - ¿El personaje es hombre y tiene sombrero?\n");
    printf("   - ¿El personaje tiene cabello negro o es mujer?\n\n");

    printf("Errores comunes:\n");
    printf("  - Usar palabras clave incorrectas o mal aplicadas.\n");
    printf("  - No especificar correctamente el atributo o el valor.\n");
    printf("  - Comandos no reconocidos o mal escritos.\n");
    printf("  - Uso de verbos con atributos que no se corresponden");
}
