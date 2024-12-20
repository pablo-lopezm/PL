
Memoria de la Práctica 2: Validador Simple de Sintaxis de un fichero XML
Autores: Iker Seoane Currás, Pablo López Martínez

Objetivo
El objetivo principal de esta práctica es desarrollar una aplicación interactiva en la terminal que implemente el juego "¿Quién es quién?" como proyecto final para la asignatura de Procesamiento de Lenguajes. Este proyecto se centra en la creación de un analizador léxico mediante FLEX y un analizador sintáctico con Bison, integrando conceptos fundamentales de la materia.

La aplicación permitirá a los usuarios formular preguntas estructuradas sobre los atributos de los personajes, como: "¿El personaje lleva sombrero?" o intento de adivinanza:"¿El personaje es Alex?"

Entre las funcionalidades avanzadas a implementar destacan:
- Preguntas complejas: Uso de conjunciones y disyunciones para combinar múltiples atributos en una sola consulta, por ejemplo:
  "¿El personaje lleva gafas o tiene el pelo rubio?" o "¿El personaje tiene bigote y viste de azul?".

- Gestión de errores: Identificación y manejo de sentencias mal formadas, proporcionando mensajes claros y específicos que guíen al usuario en la corrección de sus consultas.

- Comandos adicionales: Funcionalidades extra como:
  - Reiniciar el juego.
  - Visualizar la lista de personajes disponibles.
  - Eliminar personajes.
  - Acceder a un comando de ayuda para facilitar la interacción con el juego.

Este proyecto tiene como finalidad demostrar la capacidad de diseñar e implementar un sistema de procesamiento de lenguajes que combine análisis léxico y sintáctico para manejar un lenguaje específico.


Realización de la práctica
La implementación del proyecto se estructuró en módulos que cumplen funciones específicas para alcanzar el objetivo final. A continuación, se detalla cómo se desarrollaron las distintas partes:

1. Lógica del juego
Los ficheros game_logic.c y game_logic.h contienen la estructura central del juego, incluyendo:
- Definiciones de los personajes, representados mediante una estructura con atributos como cabello, ojos, nariz, vello facial y complementos.
- Funciones principales como la inicialización de personajes, gestión del juego, selección del personaje inicial y la lógica para formular preguntas y adivinanzas.

2. Análisis léxico
El archivo lexer.l, creado con FLEX, se encarga de analizar la entrada del usuario y dividirla en tokens que representan las partes fundamentales de las frases.

3. Análisis sintáctico
El archivo parser.y, implementado con Bison, define la gramática del juego. Este componente valida la estructura de las frases ingresadas por el usuario y gestiona los errores en caso de consultas incorrectas.

4. Flujo principal
El fichero main.c controla el flujo de ejecución del programa, llamando al analizador sintáctico para procesar cada nueva frase introducida.


Problemáticas enfrentadas durante la práctica

1. Problemas con el flujo del programa
Durante el desarrollo, surgieron inconvenientes al procesar entradas desde la consola, como:
- Entradas correctas que no eran reconocidas.
- Bloqueos y errores imprevistos.

Solución:
Se implementó un bucle que permite escanear al lexer continuamente, gestionando el buffer de entrada para reiniciarlo tras un error, descartando los tokens no procesados. Esto garantizó la continuidad del flujo del programa.

2. Reconocimiento de preguntas
El juego debía reconocer diferentes tipos de preguntas, como:
- "¿El personaje tiene gafas?"
- "¿Es rubio?"
- "¿El personaje es Alex?"

Solución:
Flex y Bison se configuraron para procesar preguntas específicas mediante tokens como ES, TIENE, ALTO, GAFAS, etc. Se añadió un nuevo token ADIVINA para manejar intentos de adivinanza.

3. Manejo de preguntas compuestas
Inicialmente, la estructura no permitía procesar preguntas compuestas de manera intuitiva.

Solución:
Se rediseñó la gramática para permitir conjunciones y disyunciones ("y", "o") sin introducir tokens forzados. Esto se logró evaluando expresiones de forma recursiva mediante un árbol lógico. También se ajustó la generación de respuestas para manejar consultas simples y compuestas, optando por respuestas genéricas pero correctas.

4. Manejo de errores
El sistema inicialmente no proporcionaba mensajes claros al usuario cuando las preguntas estaban mal estructuradas.

Solución:
Se diseñó una estructura que devuelve errores específicos para los casos más comunes, aplicable tanto a preguntas simples como compuestas.

5. Comandos de control
Se introdujeron comandos para mejorar la experiencia del usuario, como:
- Reiniciar el juego.
- Acceder a la ayuda.
- Eliminar personajes de la lista.

Implementación:
Estos comandos se implementaron como funcionalidades adicionales en el flujo principal del programa, integrándolos de forma modular.

Con esta práctica, se ha logrado implementar un sistema robusto capaz de manejar entradas estructuradas y procesar lenguaje natural, demostrando el potencial del análisis léxico y sintáctico en el diseño de aplicaciones interactivas.
