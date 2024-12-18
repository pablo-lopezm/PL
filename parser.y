%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_logic.h"

extern int yylex();
extern int yyparse();
extern char* yytext;

void yyerror(const char *s);
%}

%union {
    char* sval;
    int bool_val; // Para almacenar los resultados de la evaluación (0 o 1)
}

%type <bool_val> condicion condiciones
%token <sval> SALIR AYUDA REINICIAR PREGUNTA LISTA TIENE ES LLEVA ISIGN ELIMINA Y O A
%token <sval> CABELLO VELLO FACIAL NARIZ LABIOS OJOS SEXO COMPLEMENTO
%token <sval> LARGURA COLOR TIPO
%token <sval> TIPO_NARIZ TIPO_VELLO TIPO_LABIO TIPO_COMPLEMENTO NOMBRE

%%

inicio:
    linea
    ;

linea:
    comandos 
    | preguntas 
    | intentos 
    ;

comandos:
    REINICIAR { reiniciar_juego(); return 0; }
    | SALIR { salir_juego(); }
    | LISTA { mostrar_lista_personajes(); return 0; }
    | AYUDA { mostrar_ayuda();}
    | ELIMINA A NOMBRE {
        eliminar_personaje_por_nombre($2);
        mostrar_lista_personajes();
        return 0;
    }
    | error {
        yyerror("Comando no reconocido. Los comandos permitidos son: 'REINICIAR', 'SALIR', 'LISTA'.");
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
        yyerror("Pregunta mal formada. Revisa las opciones permitidas.");
        return 0;
    }
    ;

condiciones:
    condicion { 
        $$ = $1; // Caso base: una sola condición
    }
    | condicion Y condiciones { 
        $$ = $1 && $3; // Combina usando conjunción (Y)
    }
    | condicion O condiciones { 
        $$ = $1 || $3; // Combina usando disyunción (O)
    }
    ;

condicion:
    TIENE CABELLO COLOR { $$ = evaluar_condicion("cabello color", $3); }
    | TIENE CABELLO LARGURA { $$ = evaluar_condicion("cabello largura", $3); }
    | TIENE CABELLO TIPO { $$ = evaluar_condicion("cabello tipo", $3); }
    | TIENE VELLO FACIAL TIPO_VELLO { $$ = evaluar_condicion("vello facial tipo", $4); }
    | TIENE VELLO FACIAL COLOR { $$ = evaluar_condicion("vello facial color", $4); }
    | TIENE NARIZ TIPO_NARIZ { $$ = evaluar_condicion("nariz", $3); }
    | TIENE LABIOS TIPO_LABIO { $$ = evaluar_condicion("labios", $3); }
    | TIENE OJOS COLOR { $$ = evaluar_condicion("ojos", $3); }
    | ES SEXO { $$ = evaluar_condicion("sexo", $2); }
    | LLEVA COMPLEMENTO { $$ = evaluar_condicion("complemento", $2); }
    | ES CABELLO COLOR { 
        yyerror("Error: Uso incorrecto del verbo 'es' debes utilizar 'tiene'");
    }
    | ES CABELLO LARGURA { 
        yyerror("Error: Uso incorrecto del verbo 'es' debes utilizar 'tiene'");
    }
    | ES CABELLO TIPO { 
        yyerror("Error: Uso incorrecto del verbo 'es' debes utilizar 'tiene'");
    }
    | ES VELLO FACIAL COLOR { 
        yyerror("Error: Uso incorrecto del verbo 'es' debes utilizar 'tiene'");
    }
    | ES VELLO FACIAL TIPO { 
        yyerror("Error: Uso incorrecto del verbo 'es' debes utilizar 'tiene'");
    }
    | ES NARIZ { 
        yyerror("Error: Uso incorrecto del verbo 'es' debes utilizar 'tiene'");
    }
    | ES LABIOS { 
        yyerror("Error: Uso incorrecto del verbo 'es' debes utilizar 'tiene'");
    }
    | ES OJOS COLOR { 
        yyerror("Error: Uso incorrecto del verbo 'es' debes utilizar 'tiene'");
    }
    | TIENE SEXO {
        yyerror("Error: Uso incorrecto del verbo 'tiene' debes utilizar 'es'");
        return 1;
    }
    | ES COMPLEMENTO {
        yyerror("Error: Uso incorrecto del verbo 'tiene' debes utilizar 'es'");
    }
    ;



intentos:
    PREGUNTA ES NOMBRE ISIGN {
        manejar_adivinanza($3);
        return 0;
    }
    
%%

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}

