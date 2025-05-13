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
    NUMBER = 258,                  /* NUMBER  */
    IDENTIFIER = 259,              /* IDENTIFIER  */
    DURATION = 260,                /* DURATION  */
    ZONE = 261,                    /* ZONE  */
    PLANT = 262,                   /* PLANT  */
    WATER = 263,                   /* WATER  */
    HARVEST = 264,                 /* HARVEST  */
    FERTILIZE = 265,               /* FERTILIZE  */
    PRUNE = 266,                   /* PRUNE  */
    WAIT = 267,                    /* WAIT  */
    LOOP = 268,                    /* LOOP  */
    TIMES = 269,                   /* TIMES  */
    IF = 270,                      /* IF  */
    ELSE = 271,                    /* ELSE  */
    AT = 272,                      /* AT  */
    IN = 273,                      /* IN  */
    FOR = 274,                     /* FOR  */
    FROM = 275,                    /* FROM  */
    MOISTURE_SENSOR = 276,         /* MOISTURE_SENSOR  */
    TEMPERATURE_SENSOR = 277,      /* TEMPERATURE_SENSOR  */
    HUMIDITY_SENSOR = 278,         /* HUMIDITY_SENSOR  */
    TEMPERATURE = 279,             /* TEMPERATURE  */
    HUMIDITY = 280,                /* HUMIDITY  */
    RAIN = 281,                    /* RAIN  */
    SOIL_MOISTURE = 282,           /* SOIL_MOISTURE  */
    WEATHER = 283,                 /* WEATHER  */
    EQ = 284,                      /* EQ  */
    LT = 285,                      /* LT  */
    GT = 286,                      /* GT  */
    LE = 287,                      /* LE  */
    GE = 288,                      /* GE  */
    PERCENT = 289,                 /* PERCENT  */
    NEWLINE = 290,                 /* NEWLINE  */
    VARCOMP = 291                  /* VARCOMP  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "parser.y"

    int number;
    char *identifier;
    char* str;
    struct {
        int val;
        char unit;
    } duration;
    struct {
        int x;
        int y;
    } coord;

#line 114 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
