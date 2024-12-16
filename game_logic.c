#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "game_logic.h"

// Definir la estructura con los atributos solicitados
typedef struct {
    char nombre[50];
    struct {
        char color[20];    // Color del cabello
        char largura[20];  // Largura del cabello (corto, largo, calvo)
        char tipo[20];     // Tipo del cabello (liso, rizado)
    } cabello;
    struct {
        char color[20];    // Color del vello facial
        char tipo[20];     // Tipo del vello facial (barba, bigote, etc.)
    } vello_facial;
    char nariz[20];        // Nariz grande o pequeña
    char labios[20];       // Labios gruesos o finos
    char ojos[20];         // Color de los ojos
    char complemento[50];  // Complemento (ej. gafas, sombrero, etc.)
    char sexo[10];         // Sexo del personaje
} Personaje;

// Variables globales
Personaje personajes[10];
int num_personajes = 0;
Personaje* personaje_actual = NULL; // Personaje seleccionado

// Función para inicializar los personajes con los datos especificados
void inicializar_personajes() {
    num_personajes = 10;

    Personaje personajes_inicializados[10] = {
        {"Alex", {"negro", "corto", "liso"}, {"negro", "bigote"}, "pequeña", "gruesos", "marrones", "", "masculino"},
        {"Alfred", {"pelirrojo", "largo", "liso"}, {"pelirrojo", "bigote"}, "pequeña", "finos", "azules", "", "masculino"},
        {"Anita", {"rubio", "largo", "liso"}, {"", ""}, "pequeña", "finos", "azules", "lazos", "femenino"},
        {"Anne", {"castaño", "largo", "rizado"}, {"", ""}, "grande", "finos", "marrones", "pendientes", "femenino"},
        {"Bernard", {"castaño", "corto", "liso"}, {"", ""}, "grande", "finos", "marrones", "gorro", "masculino"},
        {"David", {"rubio", "corto", "liso"}, {"rubio", "barba"}, "pequeña", "gruesos", "marrones", "", "masculino"},
        {"Eric", {"rubio", "corto", "liso"}, {"", ""}, "pequeña", "gruesos", "negros", "gorro policía", "masculino"},
        {"Frans", {"pelirrojo", "corto", "rizado"}, {"", ""}, "pequeña", "finos", "marrones", "", "masculino"},
        {"George", {"blanco", "corto", "liso"}, {"", ""}, "pequeña", "gruesos", "marrones", "sombrero", "masculino"},
        {"Herman", {"", "calvo", ""}, {"", ""}, "grande", "gruesos", "marrones", "", "masculino"}
    };

    // Copiar los personajes inicializados al array global
    for (int i = 0; i < num_personajes; i++) {
        personajes[i] = personajes_inicializados[i];
    }
}

// Función para manejar preguntas y respuestas
void manejar_pregunta(const char* atributo, const char* valor) {
    if (personaje_actual == NULL) {
        printf("Error: No hay un personaje seleccionado.\n");
        return;
    }

    // Verificar los atributos del personaje actual
    if (strcmp(atributo, "cabello color") == 0) {
        if (strcmp(personaje_actual->cabello.color, valor) == 0) {
            printf("Respuesta: Sí, el personaje tiene cabello de color %s.\n", valor);
        } else {
            printf("Respuesta: No, el personaje no tiene cabello de color %s.\n", valor);
        }
    } else if (strcmp(atributo, "cabello largura") == 0) {
        if (strcmp(personaje_actual->cabello.largura, valor) == 0) {
            printf("Respuesta: Sí, el personaje tiene cabello %s.\n", valor);
        } else {
            printf("Respuesta: No, el personaje no tiene cabello %s.\n", valor);
        }
    } else if (strcmp(atributo, "cabello tipo") == 0) {
        if (strcmp(personaje_actual->cabello.tipo, valor) == 0) {
            printf("Respuesta: Sí, el personaje tiene cabello %s.\n", valor);
        } else {
            printf("Respuesta: No, el personaje no tiene cabello %s.\n", valor);
        }
    } else if (strcmp(atributo, "vello facial color") == 0) {
        if (strcmp(personaje_actual->vello_facial.color, valor) == 0) {
            printf("Respuesta: Sí, el personaje tiene vello facial de color %s.\n", valor);
        } else {
            printf("Respuesta: No, el personaje no tiene vello facial de color %s.\n", valor);
        }
    } else if (strcmp(atributo, "vello facial tipo") == 0) {
        if (strcmp(personaje_actual->vello_facial.tipo, valor) == 0) {
            printf("Respuesta: Sí, el personaje tiene %s.\n", valor);
        } else {
            printf("Respuesta: No, el personaje no tiene %s.\n", valor);
        }
    } else if (strcmp(atributo, "nariz") == 0) {
        if (strcmp(personaje_actual->nariz, valor) == 0) {
            printf("Respuesta: Sí, el personaje tiene nariz %s.\n", valor);
        } else {
            printf("Respuesta: No, el personaje no tiene nariz %s.\n", valor);
        }
    } else if (strcmp(atributo, "labios") == 0) {
        if (strcmp(personaje_actual->labios, valor) == 0) {
            printf("Respuesta: Sí, el personaje tiene labios %s.\n", valor);
        } else {
            printf("Respuesta: No, el personaje no tiene labios %s.\n", valor);
        }
    } else if (strcmp(atributo, "ojos") == 0) {
        if (strcmp(personaje_actual->ojos, valor) == 0) {
            printf("Respuesta: Sí, el personaje tiene ojos %s.\n", valor);
        } else {
            printf("Respuesta: No, el personaje no tiene ojos %s.\n", valor);
        }
    } else if (strcmp(atributo, "complemento") == 0) {
        if (strcmp(personaje_actual->complemento, valor) == 0) {
            printf("Respuesta: Sí, el personaje lleva %s.\n", valor);
        } else {
            printf("Respuesta: No, el personaje no lleva %s.\n", valor);
        }
    } else if (strcmp(atributo, "sexo") == 0) {
        if (strcmp(personaje_actual->sexo, valor) == 0) {
            printf("Respuesta: Sí, el personaje es %s.\n", valor);
        } else {
            printf("Respuesta: No, el personaje no es %s.\n", valor);
        }
    } else {
        printf("Atributo desconocido.\n");
    }
}



// Función para manejar adivinanzas
void manejar_adivinanza(const char* nombre) {
    printf("Intento: ¿El personaje es %s?\n", nombre);

    if (personaje_actual != NULL && strcmp(personaje_actual->nombre, nombre) == 0) {
        printf("¡Correcto! El personaje era %s.\n", personaje_actual->nombre);
        reiniciar_juego(); // Elegir un nuevo personaje
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

// Función para reiniciar el juego y seleccionar un nuevo personaje
void reiniciar_juego() {
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
