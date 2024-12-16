%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"  // Incluir el archivo generado por el parser

%}

%option noyywrap

salir        salir
reiniciar    reiniciar
lista        lista
tiene        tiene
es           es
lleva        lleva
y            y 
o            o

cabello      cabello
vello_facial vello_facial
nariz        nariz
labios       labios
ojos         ojos

sexo         (hombre|mujer)
color        (negro|blanco|rubio|castaño|pelirrojo|marrones|azules|verdes|rosado|gris)
largura      (corto|largo|calvo)
tipo         (liso|rizado)
tipo_vello   (barba|bigote|sin_vello)
tipo_nariz   (grande|pequeña)
tipo_labios  (gruesos|finos)
complemento  (gorro|sombrero|lazos|pendientes|gafas|corbata)

nombre       [a-zA-Z][a-zA-Z]*  

%%

{salir}          { return SALIR; }
{reiniciar}      { return REINICIAR; }
{lista}          { return LISTA; }
"¿El personaje"  { return PREGUNTA; }
{tiene}          { return TIENE; }
{lleva}          { return LLEVA; }
{es}             { return ES; }
"?"              { return ISIGN; }
{cabello}        { return CABELLO; }
{vello_facial}   { return VELLO_FACIAL; }
{nariz}          { return NARIZ; }
{labios}         { return LABIOS; }
{ojos}           { return OJOS; }

{sexo}           { yylval.sval = strdup(yytext); return SEXO; }
{color}          { yylval.sval = strdup(yytext); return COLOR; }
{largura}        { yylval.sval = strdup(yytext); return LARGURA; }
{tipo}           { yylval.sval = strdup(yytext); return TIPO; }
{tipo_vello}     { yylval.sval = strdup(yytext); return TIPO_VELLO; }
{tipo_nariz}     { yylval.sval = strdup(yytext); return TIPO_NARIZ; }
{tipo_labios}    { yylval.sval = strdup(yytext); return TIPO_LABIO; }
{complemento}    { yylval.sval = strdup(yytext); return COMPLEMENTO; }

{nombre}         { yylval.sval = strdup(yytext); return NOMBRE; }

[ \t\r\n]+        { /* Ignorar espacios, tabulaciones y saltos de línea */ }

.                { printf("Carácter desconocido: %c\n", yytext[0]); }

%%
