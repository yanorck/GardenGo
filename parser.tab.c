/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// O que é específico para as AÇÕES do parser fica aqui
#include "ast.h"

void yyerror(struct AST_Node** ast_root, const char* s);

extern int yylex();
extern int yylineno;

#line 85 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_IDENTIFIER = 4,                 /* IDENTIFIER  */
  YYSYMBOL_DURATION = 5,                   /* DURATION  */
  YYSYMBOL_ZONE = 6,                       /* ZONE  */
  YYSYMBOL_PLANT = 7,                      /* PLANT  */
  YYSYMBOL_WATER = 8,                      /* WATER  */
  YYSYMBOL_HARVEST = 9,                    /* HARVEST  */
  YYSYMBOL_FERTILIZE = 10,                 /* FERTILIZE  */
  YYSYMBOL_PRUNE = 11,                     /* PRUNE  */
  YYSYMBOL_WAIT = 12,                      /* WAIT  */
  YYSYMBOL_LOOP = 13,                      /* LOOP  */
  YYSYMBOL_TIMES = 14,                     /* TIMES  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_AT = 17,                        /* AT  */
  YYSYMBOL_IN = 18,                        /* IN  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_FROM = 20,                      /* FROM  */
  YYSYMBOL_MOISTURE_SENSOR = 21,           /* MOISTURE_SENSOR  */
  YYSYMBOL_TEMPERATURE_SENSOR = 22,        /* TEMPERATURE_SENSOR  */
  YYSYMBOL_HUMIDITY_SENSOR = 23,           /* HUMIDITY_SENSOR  */
  YYSYMBOL_TEMPERATURE = 24,               /* TEMPERATURE  */
  YYSYMBOL_HUMIDITY = 25,                  /* HUMIDITY  */
  YYSYMBOL_RAIN = 26,                      /* RAIN  */
  YYSYMBOL_SOIL_MOISTURE = 27,             /* SOIL_MOISTURE  */
  YYSYMBOL_WEATHER = 28,                   /* WEATHER  */
  YYSYMBOL_EQ = 29,                        /* EQ  */
  YYSYMBOL_LT = 30,                        /* LT  */
  YYSYMBOL_GT = 31,                        /* GT  */
  YYSYMBOL_LE = 32,                        /* LE  */
  YYSYMBOL_GE = 33,                        /* GE  */
  YYSYMBOL_PERCENT = 34,                   /* PERCENT  */
  YYSYMBOL_NEWLINE = 35,                   /* NEWLINE  */
  YYSYMBOL_DOT = 36,                       /* DOT  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_38_ = 38,                       /* ')'  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_41_ = 41,                       /* ','  */
  YYSYMBOL_42_ = 42,                       /* '-'  */
  YYSYMBOL_43_ = 43,                       /* '='  */
  YYSYMBOL_IF_THEN_ELSE = 44,              /* IF_THEN_ELSE  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_statements = 47,                /* statements  */
  YYSYMBOL_statement = 48,                 /* statement  */
  YYSYMBOL_zone_decl = 49,                 /* zone_decl  */
  YYSYMBOL_COORD = 50,                     /* COORD  */
  YYSYMBOL_plant_stmt = 51,                /* plant_stmt  */
  YYSYMBOL_PLANT_TYPE = 52,                /* PLANT_TYPE  */
  YYSYMBOL_IN_OPTION = 53,                 /* IN_OPTION  */
  YYSYMBOL_water_stmt = 54,                /* water_stmt  */
  YYSYMBOL_IF_CLAUSE = 55,                 /* IF_CLAUSE  */
  YYSYMBOL_condition = 56,                 /* condition  */
  YYSYMBOL_SOIL_COND = 57,                 /* SOIL_COND  */
  YYSYMBOL_WEATHER_COND = 58,              /* WEATHER_COND  */
  YYSYMBOL_SENSOR_COND = 59,               /* SENSOR_COND  */
  YYSYMBOL_SENSOR_TYPE = 60,               /* SENSOR_TYPE  */
  YYSYMBOL_WEATHER_FIELD = 61,             /* WEATHER_FIELD  */
  YYSYMBOL_COMP = 62,                      /* COMP  */
  YYSYMBOL_VALUE = 63,                     /* VALUE  */
  YYSYMBOL_PERCENT_OPT = 64,               /* PERCENT_OPT  */
  YYSYMBOL_AT_CLAUSE_COORD = 65,           /* AT_CLAUSE_COORD  */
  YYSYMBOL_harvest_stmt = 66,              /* harvest_stmt  */
  YYSYMBOL_FROM_OPTION = 67,               /* FROM_OPTION  */
  YYSYMBOL_fertilize_stmt = 68,            /* fertilize_stmt  */
  YYSYMBOL_FERTILIZER_TYPE = 69,           /* FERTILIZER_TYPE  */
  YYSYMBOL_prune_stmt = 70,                /* prune_stmt  */
  YYSYMBOL_wait_stmt = 71,                 /* wait_stmt  */
  YYSYMBOL_loop_stmt = 72,                 /* loop_stmt  */
  YYSYMBOL_block = 73,                     /* block  */
  YYSYMBOL_if_stmt = 74                    /* if_stmt  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   109

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      37,    38,     2,     2,    41,    42,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    61,    61,    67,    68,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    81,    83,    85,    87,    89,
      89,    91,    93,    93,    95,    95,    95,    97,    99,   101,
     103,   103,   103,   105,   105,   105,   107,   107,   107,   107,
     107,   109,   111,   111,   113,   113,   115,   117,   117,   119,
     121,   123,   125,   127,   129,   131,   132
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "IDENTIFIER",
  "DURATION", "ZONE", "PLANT", "WATER", "HARVEST", "FERTILIZE", "PRUNE",
  "WAIT", "LOOP", "TIMES", "IF", "ELSE", "AT", "IN", "FOR", "FROM",
  "MOISTURE_SENSOR", "TEMPERATURE_SENSOR", "HUMIDITY_SENSOR",
  "TEMPERATURE", "HUMIDITY", "RAIN", "SOIL_MOISTURE", "WEATHER", "EQ",
  "LT", "GT", "LE", "GE", "PERCENT", "NEWLINE", "DOT", "'('", "')'", "'{'",
  "'}'", "','", "'-'", "'='", "IF_THEN_ELSE", "$accept", "program",
  "statements", "statement", "zone_decl", "COORD", "plant_stmt",
  "PLANT_TYPE", "IN_OPTION", "water_stmt", "IF_CLAUSE", "condition",
  "SOIL_COND", "WEATHER_COND", "SENSOR_COND", "SENSOR_TYPE",
  "WEATHER_FIELD", "COMP", "VALUE", "PERCENT_OPT", "AT_CLAUSE_COORD",
  "harvest_stmt", "FROM_OPTION", "fertilize_stmt", "FERTILIZER_TYPE",
  "prune_stmt", "wait_stmt", "loop_stmt", "block", "if_stmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -72,     5,    13,   -72,     4,    23,   -20,    23,    25,    23,
      31,    38,    12,   -72,   -72,     9,    22,    24,    26,    27,
      28,    29,    30,    32,    15,   -72,    43,    52,    46,   -72,
      51,    53,   -72,    55,   -72,   -72,   -72,    20,    35,    33,
     -72,   -72,   -72,    20,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,    36,    37,    34,    39,    72,   -72,    41,
      42,    33,   -72,   -72,   -72,   -72,   -72,    77,    21,   -72,
      65,    77,    52,    52,    79,    64,   -72,    52,    52,   -72,
      50,    68,   -72,   -72,   -72,    20,     3,    33,    68,    44,
      49,   -72,    83,    54,    56,   -72,   -72,    58,   -72,    77,
     -72,   -72,   -72,    52,    71,    75,    74,   -72,    52,   -72,
      59,    87,   -72,    12,   -72,    91,    60,   -72,   -72,   -72,
     -72,   -72
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,    47,    50,
       0,     0,    52,     0,    30,    31,    32,     0,     0,     0,
      24,    25,    26,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,     0,     0,     0,     0,     0,    46,     0,
       0,     0,    38,    36,    37,    39,    40,     0,     0,     3,
      55,     0,     0,     0,     0,     0,    48,     0,     0,    53,
      42,    44,    33,    34,    35,     0,     0,     0,    44,     0,
       0,    16,     0,     0,     0,    43,    41,     0,    27,     0,
      54,    56,    29,     0,    19,    22,     0,    51,     0,    28,
       0,     0,    17,     0,    21,     0,     0,    15,    20,    23,
      49,    45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -72,   -72,    40,   -72,   -72,   -71,   -72,    47,   -72,   -72,
     -72,   -14,   -72,   -72,   -72,   -72,   -72,   -43,   -68,   -72,
      14,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -57,   -72
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    14,    15,    56,    16,    26,   112,    17,
     114,    39,    40,    41,    42,    43,    85,    67,    81,    96,
      98,    18,    58,    19,    30,    20,    21,    22,    70,    23
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      71,    89,    90,    88,    79,     3,    93,    94,    24,     4,
       5,     6,     7,     8,     9,    10,    11,    27,    12,     4,
       5,     6,     7,     8,     9,    10,    11,    25,    12,    29,
     101,   109,   110,    34,    35,    36,    32,   116,    13,    37,
      38,    33,    99,   100,    44,    82,    83,    84,    13,    62,
      63,    64,    65,    66,    28,    55,    31,    45,    53,    46,
      54,    47,    48,    49,    50,    51,    57,    52,    59,    61,
      60,    68,    69,    72,    73,    74,    76,    75,    77,    78,
      80,    87,    91,    92,    95,    97,   103,   104,   105,   111,
     113,   118,   106,   115,   107,   108,   120,   117,   121,   119,
       0,     0,   102,     0,     0,     0,     0,     0,     0,    86
};

static const yytype_int8 yycheck[] =
{
      43,    72,    73,    71,    61,     0,    77,    78,     4,     6,
       7,     8,     9,    10,    11,    12,    13,    37,    15,     6,
       7,     8,     9,    10,    11,    12,    13,     4,    15,     4,
      87,    99,   103,    21,    22,    23,     5,   108,    35,    27,
      28,     3,    85,    40,    35,    24,    25,    26,    35,    29,
      30,    31,    32,    33,     7,     3,     9,    35,    43,    35,
      17,    35,    35,    35,    35,    35,    20,    35,    17,    14,
      17,    36,    39,    37,    37,    41,     4,    38,    37,    37,
       3,    16,     3,    19,    34,    17,    42,    38,     5,    18,
      15,     4,    38,    19,    38,    37,     5,    38,    38,   113,
      -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    69
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    46,    47,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    15,    35,    48,    49,    51,    54,    66,    68,
      70,    71,    72,    74,     4,     4,    52,    37,    52,     4,
      69,    52,     5,     3,    21,    22,    23,    27,    28,    56,
      57,    58,    59,    60,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    43,    17,     3,    50,    20,    67,    17,
      17,    14,    29,    30,    31,    32,    33,    62,    36,    39,
      73,    62,    37,    37,    41,    38,     4,    37,    37,    73,
       3,    63,    24,    25,    26,    61,    47,    16,    63,    50,
      50,     3,    19,    50,    50,    34,    64,    17,    65,    62,
      40,    73,    65,    42,    38,     5,    38,    38,    37,    63,
      50,    18,    53,    15,    55,    19,    50,    38,     4,    56,
       5,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    49,    50,    51,    52,    53,
      53,    54,    55,    55,    56,    56,    56,    57,    58,    59,
      60,    60,    60,    61,    61,    61,    62,    62,    62,    62,
      62,    63,    64,    64,    65,    65,    66,    67,    67,    68,
      69,    70,    71,    72,    73,    74,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     8,     3,     7,     1,     0,
       2,     7,     0,     2,     1,     1,     1,     4,     5,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     0,     1,     0,     4,     3,     0,     2,     8,
       1,     6,     2,     4,     3,     3,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (ast_root, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, ast_root); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, struct AST_Node** ast_root)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (ast_root);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, struct AST_Node** ast_root)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, ast_root);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, struct AST_Node** ast_root)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], ast_root);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, ast_root); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, struct AST_Node** ast_root)
{
  YY_USE (yyvaluep);
  YY_USE (ast_root);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (struct AST_Node** ast_root)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: statements  */
#line 62 "parser.y"
         {
             *ast_root = (yyvsp[0].node);
         }
#line 1226 "parser.tab.c"
    break;

  case 3: /* statements: %empty  */
#line 67 "parser.y"
                                   { (yyval.node) = NULL; }
#line 1232 "parser.tab.c"
    break;

  case 4: /* statements: statements statement  */
#line 68 "parser.y"
                                  { if ((yyvsp[0].node) != NULL) { (yyval.node) = ast_create_sequence_node((yyvsp[-1].node), (yyvsp[0].node)); } else { (yyval.node) = (yyvsp[-1].node); } }
#line 1238 "parser.tab.c"
    break;

  case 5: /* statement: zone_decl NEWLINE  */
#line 70 "parser.y"
                                  { (yyval.node) = (yyvsp[-1].node); }
#line 1244 "parser.tab.c"
    break;

  case 6: /* statement: plant_stmt NEWLINE  */
#line 71 "parser.y"
                                  { (yyval.node) = (yyvsp[-1].node); }
#line 1250 "parser.tab.c"
    break;

  case 7: /* statement: water_stmt NEWLINE  */
#line 72 "parser.y"
                                  { (yyval.node) = (yyvsp[-1].node); }
#line 1256 "parser.tab.c"
    break;

  case 8: /* statement: harvest_stmt NEWLINE  */
#line 73 "parser.y"
                                  { (yyval.node) = (yyvsp[-1].node); }
#line 1262 "parser.tab.c"
    break;

  case 9: /* statement: fertilize_stmt NEWLINE  */
#line 74 "parser.y"
                                  { (yyval.node) = (yyvsp[-1].node); }
#line 1268 "parser.tab.c"
    break;

  case 10: /* statement: prune_stmt NEWLINE  */
#line 75 "parser.y"
                                  { (yyval.node) = (yyvsp[-1].node); }
#line 1274 "parser.tab.c"
    break;

  case 11: /* statement: wait_stmt NEWLINE  */
#line 76 "parser.y"
                                  { (yyval.node) = (yyvsp[-1].node); }
#line 1280 "parser.tab.c"
    break;

  case 12: /* statement: loop_stmt NEWLINE  */
#line 77 "parser.y"
                                  { (yyval.node) = (yyvsp[-1].node); }
#line 1286 "parser.tab.c"
    break;

  case 13: /* statement: if_stmt NEWLINE  */
#line 78 "parser.y"
                                  { (yyval.node) = (yyvsp[-1].node); }
#line 1292 "parser.tab.c"
    break;

  case 14: /* statement: NEWLINE  */
#line 79 "parser.y"
                                  { (yyval.node) = NULL; }
#line 1298 "parser.tab.c"
    break;

  case 15: /* zone_decl: ZONE IDENTIFIER '=' '(' COORD '-' COORD ')'  */
#line 81 "parser.y"
                                                       { (yyval.node) = ast_create_zone_decl_node((yyvsp[-6].identifier), (yyvsp[-3].coord), (yyvsp[-1].coord)); }
#line 1304 "parser.tab.c"
    break;

  case 16: /* COORD: NUMBER ',' NUMBER  */
#line 83 "parser.y"
                         { (yyval.coord).x = (yyvsp[-2].number); (yyval.coord).y = (yyvsp[0].number); }
#line 1310 "parser.tab.c"
    break;

  case 17: /* plant_stmt: PLANT PLANT_TYPE AT '(' COORD ')' IN_OPTION  */
#line 85 "parser.y"
                                                        { (yyval.node) = ast_create_plant_node((yyvsp[-5].identifier), (yyvsp[-2].coord), (yyvsp[0].identifier)); }
#line 1316 "parser.tab.c"
    break;

  case 18: /* PLANT_TYPE: IDENTIFIER  */
#line 87 "parser.y"
                       { (yyval.identifier) = (yyvsp[0].identifier); }
#line 1322 "parser.tab.c"
    break;

  case 19: /* IN_OPTION: %empty  */
#line 89 "parser.y"
                       { (yyval.identifier) = NULL; }
#line 1328 "parser.tab.c"
    break;

  case 20: /* IN_OPTION: IN IDENTIFIER  */
#line 89 "parser.y"
                                                      { (yyval.identifier) = (yyvsp[0].identifier); }
#line 1334 "parser.tab.c"
    break;

  case 21: /* water_stmt: WATER '(' COORD ')' FOR DURATION IF_CLAUSE  */
#line 91 "parser.y"
                                                       { (yyval.node) = ast_create_water_node((yyvsp[-4].coord), (yyvsp[-1].duration), (yyvsp[0].node)); }
#line 1340 "parser.tab.c"
    break;

  case 22: /* IF_CLAUSE: %empty  */
#line 93 "parser.y"
                       { (yyval.node) = NULL; }
#line 1346 "parser.tab.c"
    break;

  case 23: /* IF_CLAUSE: IF condition  */
#line 93 "parser.y"
                                                     { (yyval.node) = (yyvsp[0].node); }
#line 1352 "parser.tab.c"
    break;

  case 24: /* condition: SOIL_COND  */
#line 95 "parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1358 "parser.tab.c"
    break;

  case 25: /* condition: WEATHER_COND  */
#line 95 "parser.y"
                                                 { (yyval.node) = (yyvsp[0].node); }
#line 1364 "parser.tab.c"
    break;

  case 26: /* condition: SENSOR_COND  */
#line 95 "parser.y"
                                                                            { (yyval.node) = (yyvsp[0].node); }
#line 1370 "parser.tab.c"
    break;

  case 27: /* SOIL_COND: SOIL_MOISTURE COMP VALUE AT_CLAUSE_COORD  */
#line 97 "parser.y"
                                                    { (yyval.node) = ast_create_soil_cond_node((yyvsp[-2].op), (yyvsp[-1].value_type), (yyvsp[0].coord)); }
#line 1376 "parser.tab.c"
    break;

  case 28: /* WEATHER_COND: WEATHER DOT WEATHER_FIELD COMP VALUE  */
#line 99 "parser.y"
                                                   { (yyval.node) = ast_create_weather_cond_node((yyvsp[-2].identifier), (yyvsp[-1].op), (yyvsp[0].value_type)); }
#line 1382 "parser.tab.c"
    break;

  case 29: /* SENSOR_COND: SENSOR_TYPE COMP VALUE AT_CLAUSE_COORD  */
#line 101 "parser.y"
                                                    { (yyval.node) = ast_create_sensor_cond_node((yyvsp[-3].identifier), (yyvsp[-2].op), (yyvsp[-1].value_type), (yyvsp[0].coord)); }
#line 1388 "parser.tab.c"
    break;

  case 30: /* SENSOR_TYPE: MOISTURE_SENSOR  */
#line 103 "parser.y"
                             { (yyval.identifier) = (yyvsp[0].identifier); }
#line 1394 "parser.tab.c"
    break;

  case 31: /* SENSOR_TYPE: TEMPERATURE_SENSOR  */
#line 103 "parser.y"
                                                               { (yyval.identifier) = (yyvsp[0].identifier); }
#line 1400 "parser.tab.c"
    break;

  case 32: /* SENSOR_TYPE: HUMIDITY_SENSOR  */
#line 103 "parser.y"
                                                                                              { (yyval.identifier) = (yyvsp[0].identifier); }
#line 1406 "parser.tab.c"
    break;

  case 33: /* WEATHER_FIELD: TEMPERATURE  */
#line 105 "parser.y"
                           { (yyval.identifier) = (yyvsp[0].identifier); }
#line 1412 "parser.tab.c"
    break;

  case 34: /* WEATHER_FIELD: HUMIDITY  */
#line 105 "parser.y"
                                                   { (yyval.identifier) = (yyvsp[0].identifier); }
#line 1418 "parser.tab.c"
    break;

  case 35: /* WEATHER_FIELD: RAIN  */
#line 105 "parser.y"
                                                                       { (yyval.identifier) = (yyvsp[0].identifier); }
#line 1424 "parser.tab.c"
    break;

  case 36: /* COMP: LT  */
#line 107 "parser.y"
         { (yyval.op) = OP_LT; }
#line 1430 "parser.tab.c"
    break;

  case 37: /* COMP: GT  */
#line 107 "parser.y"
                              { (yyval.op) = OP_GT; }
#line 1436 "parser.tab.c"
    break;

  case 38: /* COMP: EQ  */
#line 107 "parser.y"
                                                   { (yyval.op) = OP_EQ; }
#line 1442 "parser.tab.c"
    break;

  case 39: /* COMP: LE  */
#line 107 "parser.y"
                                                                        { (yyval.op) = OP_LE; }
#line 1448 "parser.tab.c"
    break;

  case 40: /* COMP: GE  */
#line 107 "parser.y"
                                                                                             { (yyval.op) = OP_GE; }
#line 1454 "parser.tab.c"
    break;

  case 41: /* VALUE: NUMBER PERCENT_OPT  */
#line 109 "parser.y"
                          { (yyval.value_type).value = (yyvsp[-1].number); (yyval.value_type).is_percent = ((yyvsp[0].number) != 0); }
#line 1460 "parser.tab.c"
    break;

  case 42: /* PERCENT_OPT: %empty  */
#line 111 "parser.y"
                         { (yyval.number) = 0; }
#line 1466 "parser.tab.c"
    break;

  case 43: /* PERCENT_OPT: PERCENT  */
#line 111 "parser.y"
                                               { (yyval.number) = 1; }
#line 1472 "parser.tab.c"
    break;

  case 44: /* AT_CLAUSE_COORD: %empty  */
#line 113 "parser.y"
                             { (yyval.coord).x = -1; (yyval.coord).y = -1; }
#line 1478 "parser.tab.c"
    break;

  case 45: /* AT_CLAUSE_COORD: AT '(' COORD ')'  */
#line 113 "parser.y"
                                                                          { (yyval.coord) = (yyvsp[-1].coord); }
#line 1484 "parser.tab.c"
    break;

  case 46: /* harvest_stmt: HARVEST PLANT_TYPE FROM_OPTION  */
#line 115 "parser.y"
                                             { (yyval.node) = ast_create_harvest_node((yyvsp[-1].identifier), (yyvsp[0].identifier)); }
#line 1490 "parser.tab.c"
    break;

  case 47: /* FROM_OPTION: %empty  */
#line 117 "parser.y"
                         { (yyval.identifier) = NULL; }
#line 1496 "parser.tab.c"
    break;

  case 48: /* FROM_OPTION: FROM IDENTIFIER  */
#line 117 "parser.y"
                                                          { (yyval.identifier) = (yyvsp[0].identifier); }
#line 1502 "parser.tab.c"
    break;

  case 49: /* fertilize_stmt: FERTILIZE FERTILIZER_TYPE AT '(' COORD ')' FOR DURATION  */
#line 119 "parser.y"
                                                                        { (yyval.node) = ast_create_fertilize_node((yyvsp[-6].identifier), (yyvsp[-3].coord), (yyvsp[0].duration)); }
#line 1508 "parser.tab.c"
    break;

  case 50: /* FERTILIZER_TYPE: IDENTIFIER  */
#line 121 "parser.y"
                            { (yyval.identifier) = (yyvsp[0].identifier); }
#line 1514 "parser.tab.c"
    break;

  case 51: /* prune_stmt: PRUNE PLANT_TYPE AT '(' COORD ')'  */
#line 123 "parser.y"
                                              { (yyval.node) = ast_create_prune_node((yyvsp[-4].identifier), (yyvsp[-1].coord)); }
#line 1520 "parser.tab.c"
    break;

  case 52: /* wait_stmt: WAIT DURATION  */
#line 125 "parser.y"
                         { (yyval.node) = ast_create_wait_node((yyvsp[0].duration).val, (yyvsp[0].duration).unit); }
#line 1526 "parser.tab.c"
    break;

  case 53: /* loop_stmt: LOOP NUMBER TIMES block  */
#line 127 "parser.y"
                                   { (yyval.node) = ast_create_loop_node((yyvsp[-2].number), (yyvsp[0].node)); }
#line 1532 "parser.tab.c"
    break;

  case 54: /* block: '{' statements '}'  */
#line 129 "parser.y"
                          { (yyval.node) = (yyvsp[-1].node); }
#line 1538 "parser.tab.c"
    break;

  case 55: /* if_stmt: IF condition block  */
#line 131 "parser.y"
                                                          { (yyval.node) = ast_create_if_node((yyvsp[-1].node), (yyvsp[0].node), NULL); }
#line 1544 "parser.tab.c"
    break;

  case 56: /* if_stmt: IF condition block ELSE block  */
#line 132 "parser.y"
                                       { (yyval.node) = ast_create_if_node((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1550 "parser.tab.c"
    break;


#line 1554 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (ast_root, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, ast_root);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, ast_root);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (ast_root, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, ast_root);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, ast_root);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 135 "parser.y"


void yyerror(struct AST_Node** ast_root, const char* s) {
    // A linha (void)ast_root; evita um aviso de "parâmetro não utilizado".
    // Estamos dizendo ao compilador que sabemos que não estamos usando, e tudo bem.
    (void)ast_root;
    fprintf(stderr, "Erro de sintaxe na linha %d: %s\n", yylineno, s);
}
