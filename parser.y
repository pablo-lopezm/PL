%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_logic.h"

extern int yylex();
extern int yyparse();
extern void limpiar_buffer();
extern char* yytext;

#define YYERROR_VERBOSE 0
void yyerror(const char *s);
%}

%union {
    char* sval;
    int bool_val; // Para almacenar los resultados de la evaluación (0 o 1)
}

%type <bool_val> condicion condiciones
%token <sval> SALIR AYUDA REINICIAR PREGUNTA LISTA TIENE ES LLEVA ISIGN ELIMINA Y O A
%token <sval> CABELLO TIPO_VELLO NARIZ LABIOS OJOS SEXO COMPLEMENTO
%token <sval> LARGURA COLOR TIPO
%token <sval> TIPO_NARIZ TIPO_LABIO TIPO_COMPLEMENTO NOMBRE ERROR
%start linea

%%

linea:
    comandos 
    | preguntas 
    | intentos 
    | error { 
        yyerror("Error: Entrada no válida. Revisa el formato o usa 'ayuda' para más información.");
        limpiar_buffer();
        return 0;
    }
    ;

comandos:
    REINICIAR { reiniciar_juego(); return 0; }
    | SALIR { salir_juego(); return 0; }
    | LISTA { mostrar_lista_personajes(); return 0; }
    | AYUDA { mostrar_ayuda(); return 0; }
    | ELIMINA A NOMBRE {
        eliminar_personaje_por_nombre($3);
        mostrar_lista_personajes();
        return 0;
    }
    ;

preguntas:
    PREGUNTA condiciones ISIGN { 
        if ($2) {
            printf("Sí, el personaje cumple esas características.\n");
        } else {
            printf("No, el personaje no cumple esas características.\n");
        }
        return 0;
    }
    | PREGUNTA error { 
        yyerror("Error: Pregunta mal formada. Revisa las opciones permitidas.");
        limpiar_buffer();
        return 0;
    }
    ;

condiciones:
    condicion { $$ = $1; }
    | condicion Y condiciones { $$ = $1 && $3; }
    | condicion O condiciones { $$ = $1 || $3; }
    | error { 
        yyerror("Error: Condición mal formada. Asegúrate de seguir el formato correcto.");
        limpiar_buffer();
        return 0;
    }
    ;

condicion:
    TIENE CABELLO COLOR { $$ = evaluar_condicion("cabello color", $3); }
    | TIENE CABELLO LARGURA { $$ = evaluar_condicion("cabello largura", $3); }
    | TIENE CABELLO TIPO { $$ = evaluar_condicion("cabello tipo", $3); }
    | TIENE TIPO_VELLO { $$ = evaluar_condicion("vello facial tipo", $2); }
    | TIENE TIPO_VELLO COLOR { $$ = evaluar_condicion("vello facial color", $3); }
    | TIENE NARIZ TIPO_NARIZ { $$ = evaluar_condicion("nariz", $3); }
    | TIENE LABIOS TIPO_LABIO { $$ = evaluar_condicion("labios", $3); }
    | TIENE OJOS COLOR { $$ = evaluar_condicion("ojos", $3); }
    | ES SEXO { $$ = evaluar_condicion("sexo", $2); }
    | LLEVA COMPLEMENTO { $$ = evaluar_condicion("complemento", $2); }
    | ES CABELLO COLOR { 
        yyerror("Error: Uso incorrecto del verbo 'es' debes utilizar 'tiene'");
        limpiar_buffer();
        return 0;
    }
    | ES CABELLO LARGURA { 
        yyerror("Error: Uso incorrecto del verbo 'es' debes utilizar 'tiene'");
        limpiar_buffer();
        return 0;
    }
    | ES CABELLO TIPO { 
        yyerror("Error: Uso incorrecto del verbo 'es' debes utilizar 'tiene'");
        limpiar_buffer();
        return 0;
    }
    | ES TIPO_VELLO COLOR { 
        yyerror("Error: Uso incorrecto del verbo 'es' debes utilizar 'tiene'");
        limpiar_buffer();
        return 0;
    }
    | ES TIPO_VELLO { 
        yyerror("Error: Uso incorrecto del verbo 'es' debes utilizar 'tiene'");
        limpiar_buffer();
        return 0;
    }
    | ES NARIZ { 
        yyerror("Error: Uso incorrecto del verbo 'es' debes utilizar 'tiene'");
        limpiar_buffer();
        return 0;
    }
    | ES LABIOS { 
        yyerror("Error: Uso incorrecto del verbo 'es' debes utilizar 'tiene'");
        limpiar_buffer();
        return 0;
    }
    | ES OJOS COLOR { 
        yyerror("Error: Uso incorrecto del verbo 'es' debes utilizar 'tiene'");
        limpiar_buffer();
        return 0;
    }
    | TIENE SEXO {
        yyerror("Error: Uso incorrecto del verbo 'tiene' debes utilizar 'es'");
        limpiar_buffer();
        return 0;
    }
    | ES COMPLEMENTO {
        yyerror("Error: Uso incorrecto del verbo 'tiene' debes utilizar 'es'");
        limpiar_buffer();
        return 0;
    }
    ;

intentos:
    PREGUNTA ES NOMBRE ISIGN {
        manejar_adivinanza($3);
        return 0;
    }
    ;

%%

void yyerror(const char *s) {
    //fprintf(stderr, "%s\n", s);
    printf("%s\n", s);
}
