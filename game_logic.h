#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

void inicializar_personajes();
void mostrar_lista_personajes();
void manejar_pregunta(const char* atributo, const char* valor);
void manejar_respuesta(const char* respuesta);
void manejar_adivinanza(const char* nombre);
void reiniciar_juego(); // Personaje al azar
void salir_juego();

#endif
