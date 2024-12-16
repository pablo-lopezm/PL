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

%token <sval> SALIR REINICIAR PREGUNTA LISTA TIENE ES LLEVA ISIGN
%token <sval> CABELLO VELLO_FACIAL NARIZ LABIOS OJOS SEXO COMPLEMENTO
%token <sval> LARGURA COLOR TIPO
%token <sval> TIPO_NARIZ TIPO_VELLO TIPO_LABIO TIPO_COMPLEMENTO NOMBRE

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
        yyerror("Entrada no válida. Revisa la gramática permitida y vuelve a intentarlo.");
        return 0;
    }
    ;

comandos:
    REINICIAR { reiniciar_juego(); return 0; }
    | SALIR { salir_juego(); }
    | LISTA { mostrar_lista_personajes(); return 0; }
    | error {
        yyerror("Comando no reconocido. Los comandos permitidos son: 'REINICIAR', 'SALIR', 'LISTA'.");
        return 0;
    }
    ;

preguntas:
    // Preguntas sobre cabello
    PREGUNTA TIENE CABELLO COLOR ISIGN {
        manejar_pregunta("cabello color", $4);
        return 0;
    }
    | PREGUNTA TIENE CABELLO LARGURA ISIGN { 
        manejar_pregunta("cabello largura", $4);
        return 0;
    }
    | PREGUNTA TIENE CABELLO TIPO ISIGN {
        manejar_pregunta("cabello tipo", $4);
        return 0;
    }

    // Preguntas sobre vello facial
    | PREGUNTA TIENE VELLO_FACIAL TIPO_VELLO ISIGN {
        manejar_pregunta("vello facial tipo", $4);
        return 0;
    }
    | PREGUNTA TIENE VELLO_FACIAL COLOR ISIGN {
        manejar_pregunta("vello facial color", $4);
        return 0;
    }

    // Preguntas sobre nariz
    | PREGUNTA TIENE NARIZ TIPO_NARIZ ISIGN {
        manejar_pregunta("nariz", $4);
        return 0;
    }

    // Preguntas sobre labios
    | PREGUNTA TIENE LABIOS TIPO_LABIO ISIGN {
        manejar_pregunta("labios", $4);
        return 0;
    }

    // Preguntas sobre ojos
    | PREGUNTA TIENE OJOS COLOR ISIGN {
        manejar_pregunta("ojos", $4);
        return 0;
    }

    // Preguntas sobre sexo
    | PREGUNTA ES SEXO ISIGN {
        manejar_pregunta("sexo", $3);
        return 0;
    }

    // Preguntas sobre complementos
    | PREGUNTA LLEVA COMPLEMENTO ISIGN {
        manejar_pregunta("complemento", $3);
        return 0;
    }

    // Errores específicos
    | PREGUNTA error {
        yyerror("Pregunta mal formada. Asegúrate de usar 'TIENE', 'ES' o 'LLEVA' correctamente.");
        return 0;
    }
    ;

intentos:
    PREGUNTA ES NOMBRE ISIGN {
        manejar_adivinanza($3);
        return 0;
    }
    | PREGUNTA ES error {
        yyerror("Adivinanza mal formada. Usa 'ES <nombre>' correctamente.");
        return 0;
    }
    ;

%%

// Manejador de errores
void yyerror(const char *s) {
    fprintf(stderr, "Error en la línea %d cerca de '%s': %s\n", yylineno, yytext, s);
}
