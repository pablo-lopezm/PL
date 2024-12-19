%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h" 
void limpiar_buffer();
%}

%option noyywrap
%option noinput nounput

salir        (salir|Salir)
reiniciar    (reiniciar|Reiniciar)
ayuda        (ayuda|Ayuda)
lista        (lista|Lista)
tiene        tiene
es           es
lleva        lleva
y            y 
o            o
a            a

cabello      cabello
nariz        nariz
labios       labios
ojos         ojos

sexo                (hombre|mujer)
color               (negro|negra|blanco|blanca|rubio|rubia|castaño|castaña|pelirrojo|pelirroja|marrones|azules|verdes|rosado|gris)
largura             (corto|largo|calvo)
tipo                (liso|rizado)
vello_facial        (barba|bigote|sin_vello)
tipo_nariz          (grande|pequeña)
tipo_labios         (gruesos|finos)
complemento         (gorro|sombrero|lazos|pendientes)
elimina             (elimina|Elimina)

nombre       (Alex|Alfred|Anita|Anne|Bernard|David|Eric|Frans|George|Herman)

%%

{salir}          { return SALIR; }
{reiniciar}      { return REINICIAR; }
{lista}          { return LISTA; }
{ayuda}          { return AYUDA; }
"¿El personaje"  { return PREGUNTA; }
{tiene}          { return TIENE; }
{lleva}          { return LLEVA; }
{es}             { return ES; }
{y}              { return Y; }
{o}              { return O;}
{a}              { return A; }
{elimina}        { return ELIMINA;}
"?"              { return ISIGN; }
{cabello}        { return CABELLO; }
{nariz}          { return NARIZ; }
{labios}         { return LABIOS; }
{ojos}           { return OJOS; }

{sexo}                  { yylval.sval = strdup(yytext); return SEXO; }
{color}                 { yylval.sval = strdup(yytext); return COLOR; }
{largura}               { yylval.sval = strdup(yytext); return LARGURA; }
{tipo}                  { yylval.sval = strdup(yytext); return TIPO; }
{vello_facial}          { yylval.sval = strdup(yytext); return TIPO_VELLO; }
{tipo_nariz}            { yylval.sval = strdup(yytext); return TIPO_NARIZ; }
{tipo_labios}           { yylval.sval = strdup(yytext); return TIPO_LABIO; }
{complemento}           { yylval.sval = strdup(yytext); return COMPLEMENTO; }

{nombre}         { yylval.sval = strdup(yytext); return NOMBRE; }

[ \t\r\n]+        { /* Ignorar espacios, tabulaciones y saltos de línea */ }

.                 {}
%%

void limpiar_buffer() {
    yy_flush_buffer(YY_CURRENT_BUFFER);
}