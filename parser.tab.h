/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SALIR = 258,                   /* SALIR  */
    AYUDA = 259,                   /* AYUDA  */
    REINICIAR = 260,               /* REINICIAR  */
    PREGUNTA = 261,                /* PREGUNTA  */
    LISTA = 262,                   /* LISTA  */
    TIENE = 263,                   /* TIENE  */
    ES = 264,                      /* ES  */
    LLEVA = 265,                   /* LLEVA  */
    ISIGN = 266,                   /* ISIGN  */
    ELIMINA = 267,                 /* ELIMINA  */
    Y = 268,                       /* Y  */
    O = 269,                       /* O  */
    A = 270,                       /* A  */
    CABELLO = 271,                 /* CABELLO  */
    VELLO = 272,                   /* VELLO  */
    FACIAL = 273,                  /* FACIAL  */
    NARIZ = 274,                   /* NARIZ  */
    LABIOS = 275,                  /* LABIOS  */
    OJOS = 276,                    /* OJOS  */
    SEXO = 277,                    /* SEXO  */
    COMPLEMENTO = 278,             /* COMPLEMENTO  */
    LARGURA = 279,                 /* LARGURA  */
    COLOR = 280,                   /* COLOR  */
    TIPO = 281,                    /* TIPO  */
    TIPO_NARIZ = 282,              /* TIPO_NARIZ  */
    TIPO_VELLO = 283,              /* TIPO_VELLO  */
    TIPO_LABIO = 284,              /* TIPO_LABIO  */
    TIPO_COMPLEMENTO = 285,        /* TIPO_COMPLEMENTO  */
    NOMBRE = 286                   /* NOMBRE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "parser.y"

    char* sval;
    int bool_val; // Para almacenar los resultados de la evaluación (0 o 1)

#line 100 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
