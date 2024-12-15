#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

void inicializar_personajes();
void manejar_pregunta(const char* atributo, const char* valor);
void manejar_respuesta(const char* respuesta);
void reiniciar_juego(); // Selecciona un nuevo personaje al azar
void salir_juego();

#endif
