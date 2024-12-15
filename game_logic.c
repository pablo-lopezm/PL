#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "game_logic.h"

typedef struct {
    char nombre[50];
    char atributos[10][50];
    int num_atributos;
} Personaje;

Personaje personajes[10];
int num_personajes = 0;
Personaje* personaje_actual = NULL; // Personaje seleccionado

void inicializar_personajes() {
    num_personajes = 10;

    // Mario
    strcpy(personajes[0].nombre, "Mario");
    personajes[0].num_atributos = 4;
    strcpy(personajes[0].atributos[0], "cabello negro");
    strcpy(personajes[0].atributos[1], "ojos azules");
    strcpy(personajes[0].atributos[2], "alto");
    strcpy(personajes[0].atributos[3], "ropa roja");

    // Luigi
    strcpy(personajes[1].nombre, "Luigi");
    personajes[1].num_atributos = 4;
    strcpy(personajes[1].atributos[0], "cabello castaño");
    strcpy(personajes[1].atributos[1], "ojos verdes");
    strcpy(personajes[1].atributos[2], "alto");
    strcpy(personajes[1].atributos[3], "ropa verde");

    // Peach
    strcpy(personajes[2].nombre, "Peach");
    personajes[2].num_atributos = 4;
    strcpy(personajes[2].atributos[0], "cabello rubio");
    strcpy(personajes[2].atributos[1], "ojos azules");
    strcpy(personajes[2].atributos[2], "mediana");
    strcpy(personajes[2].atributos[3], "ropa rosa");

    // Bowser
    strcpy(personajes[3].nombre, "Bowser");
    personajes[3].num_atributos = 4;
    strcpy(personajes[3].atributos[0], "cabello rojo");
    strcpy(personajes[3].atributos[1], "ojos amarillos");
    strcpy(personajes[3].atributos[2], "gigante");
    strcpy(personajes[3].atributos[3], "ropa amarilla");

    // Toad
    strcpy(personajes[4].nombre, "Toad");
    personajes[4].num_atributos = 3;
    strcpy(personajes[4].atributos[0], "sin cabello");
    strcpy(personajes[4].atributos[1], "ojos negros");
    strcpy(personajes[4].atributos[2], "bajo");

    // Yoshi
    strcpy(personajes[5].nombre, "Yoshi");
    personajes[5].num_atributos = 4;
    strcpy(personajes[5].atributos[0], "cabello verde");
    strcpy(personajes[5].atributos[1], "ojos marrones");
    strcpy(personajes[5].atributos[2], "medio");
    strcpy(personajes[5].atributos[3], "ropa naranja");

    // Wario
    strcpy(personajes[6].nombre, "Wario");
    personajes[6].num_atributos = 4;
    strcpy(personajes[6].atributos[0], "cabello amarillo");
    strcpy(personajes[6].atributos[1], "ojos rojos");
    strcpy(personajes[6].atributos[2], "bajo");
    strcpy(personajes[6].atributos[3], "ropa amarilla");

    // Waluigi
    strcpy(personajes[7].nombre, "Waluigi");
    personajes[7].num_atributos = 4;
    strcpy(personajes[7].atributos[0], "cabello morado");
    strcpy(personajes[7].atributos[1], "ojos morados");
    strcpy(personajes[7].atributos[2], "alto");
    strcpy(personajes[7].atributos[3], "ropa morada");

    // Donkey Kong
    strcpy(personajes[8].nombre, "Donkey Kong");
    personajes[8].num_atributos = 3;
    strcpy(personajes[8].atributos[0], "cabello marrón");
    strcpy(personajes[8].atributos[1], "ojos oscuros");
    strcpy(personajes[8].atributos[2], "gigante");

    // Toadette
    strcpy(personajes[9].nombre, "Toadette");
    personajes[9].num_atributos = 3;
    strcpy(personajes[9].atributos[0], "cabello rosa");
    strcpy(personajes[9].atributos[1], "ojos rosados");
    strcpy(personajes[9].atributos[2], "baja");
    reiniciar_juego(); // Seleccionar un personaje inicial
}

void manejar_pregunta(const char* atributo, const char* valor) {
    if (personaje_actual == NULL) {
        printf("Error: No hay un personaje seleccionado.\n");
        return;
    }

    printf("Pregunta: ¿El personaje tiene %s %s?\n", atributo, valor);
    char atributo_completo[100];
    snprintf(atributo_completo, sizeof(atributo_completo), "%s %s", atributo, valor);

    for (int i = 0; i < personaje_actual->num_atributos; i++) {
        if (strcmp(personaje_actual->atributos[i], atributo_completo) == 0) {
            printf("Respuesta: Sí, el personaje tiene %s %s.\n", atributo, valor);
            return;
        }
    }
    printf("Respuesta: No, el personaje no tiene %s %s.\n", atributo, valor);
}

void manejar_adivinanza(const char* nombre) {
    printf("Intento: ¿El personaje es %s?\n", nombre);

    if (personaje_actual != NULL && strcmp(personaje_actual->nombre, nombre) == 0) {
        printf("¡Correcto! El personaje era %s.\n", personaje_actual->nombre);
        reiniciar_juego(); // Elegir un nuevo personaje
    } else {
        printf("No, el personaje no es %s. ¡Sigue intentando!\n", nombre);
    }
}

void mostrar_lista_personajes() {
    printf("Lista de personajes:\n");
    for (int i = 0; i < num_personajes; i++) {
        printf("- %s\n", personajes[i].nombre);
    }
}

void reiniciar_juego() {
    srand(time(NULL));
    int indice = rand() % num_personajes;
    personaje_actual = &personajes[indice];

    printf("Un nuevo personaje ha sido seleccionado. ¡Comienza el juego!\n");
}

void salir_juego() {
    printf("Gracias por jugar. ¡Hasta luego!\n");
    exit(0);
}
