%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"  

%}

%option noyywrap


salir       salir
reiniciar   reiniciar
lista       lista
tiene       tiene
es          es
nombre      [a-zA-Z][a-zA-Z]*    

%%

{salir}          { return SALIR; }
{reiniciar}      { return REINICIAR; }
{lista}          { return LISTA; }
"¿El personaje"  { return PREGUNTA; }
{tiene}          { return TIENE; }
{es}             { return ES; }
"?"              { return '?'; }
{nombre}         { yylval.sval = strdup(yytext);return NOMBRE;}
[ \t\r\n]+         {  }

.                { printf("Carácter desconocido: %c\n", yytext[0]); }
%%

